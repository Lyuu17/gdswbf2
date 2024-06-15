#include <godot_cpp/variant/utility_functions.hpp>

#include "StreamReader.hpp"

#include "FNVHash.hpp"

#include "ModelSegmentChunk.hpp"

namespace SWBF2::Native
{
    void ModelSegmentChunk::ProcessChunk(StreamReader &streamReader, Model &model)
    {
        ModelSegment segment;

        auto infoReaderChild = streamReader.ReadChildWithHeader<"INFO"_m>();
        {
            *infoReaderChild >> segment.m_primitiveType;
            *infoReaderChild >> segment.m_vertexCount;
            *infoReaderChild >> segment.m_primitiveCount;
        }

        std::optional<StreamReader> readerChild;
        while ((readerChild = streamReader.ReadChild()).has_value())
        {
            switch (readerChild->GetHeader().m_Magic)
            {
                case "MTRL"_m:
                {
                    Material mat;
                    *readerChild >> mat.m_flags;
                    *readerChild >> mat.m_diffuseColor.color32;
                    *readerChild >> mat.m_specularColor.color32;
                    *readerChild >> mat.m_specularExponent;
                    *readerChild >> mat.m_parameters;
                    *readerChild >> mat.m_attachedLight;

                    segment.m_material = mat;

                    break;
                }
                case "RTYP"_m:
                {
                    *readerChild >> segment.p_renderType;
                    break;
                }
                case "IBUF"_m:
                {
                    *readerChild >> segment.m_indicesBuf.m_indicesCount;

                    segment.m_indicesBuf.m_indices.resize(segment.m_indicesBuf.m_indicesCount);

                    *readerChild >> segment.m_indicesBuf.m_indices;
                    break;
                }
                case "VBUF"_m:
                {
                    *readerChild >> segment.m_verticesBuf.m_verticesCount;
                    *readerChild >> segment.m_verticesBuf.m_stride;
                    *readerChild >> segment.m_verticesBuf.m_flags;

                    for (uint32_t i = 0; i < segment.m_verticesBuf.m_verticesCount; ++i)
                    {
                        ProcessVerticesBuffer(*readerChild, model, segment);
                    }

                    break;
                }
                case "TNAM"_m:
                {
                    uint32_t index;
                    *readerChild >> index;

                    std::string texName;
                    *readerChild >> texName;

                    string_tolower(texName);
                    segment.m_textureNames[index] = texName;

                    break;
                }
                case "BNAM"_m:
                case "SKIN"_m:
                case "BMAP"_m:
                case "MNAM"_m:
                default:
                    godot::UtilityFunctions::printerr(__FILE__, ":", __LINE__, ": ", readerChild->GetHeader().ToString().c_str(), " not implemented");
                    break;
            }
        }

        model.m_segments.push_back(segment);
    }

    void ModelSegmentChunk::ProcessVerticesBuffer(StreamReader &streamReader, Model &model, ModelSegment &segment)
    {
        if ((segment.m_verticesBuf.m_flags & VBUFFlags::Position) != 0)
        {
            if ((segment.m_verticesBuf.m_flags & VBUFFlags::PositionCompressed) != 0)
            {
                Vector3<float> low = model.m_info.m_vertexBox[0];
                Vector3<float> mul = model.m_info.m_vertexBox[1] - model.m_info.m_vertexBox[0];

                int16_t data[4];
                streamReader >> data;
                Vector3<float> c(data[0], data[1], data[2]);

                constexpr float i16min = std::numeric_limits<int16_t>::min();
                constexpr float i16max = std::numeric_limits<int16_t>::max();

                segment.m_verticesBuf.m_positions.push_back((low + (c - i16min) * mul / (i16max - i16min)));
            }
            else
            {
                Vector3<float> vec3;
                streamReader >> vec3;

                segment.m_verticesBuf.m_positions.push_back(vec3);
            }
        }

        if ((segment.m_verticesBuf.m_flags & VBUFFlags::BlendWeight) != 0)
        {
            if ((segment.m_verticesBuf.m_flags & VBUFFlags::BlendWeightCompressed) != 0)
            {
                int8_t data[4];
                streamReader >> data;

                float_t one = (float)data[1], two = (float)data[2];
                segment.m_verticesBuf.m_weights.push_back({ two, one, 1.0f - two - one });
            }
            else
            {
                Vector2<float> vec2;
                streamReader >> vec2;

                segment.m_verticesBuf.m_weights.push_back({ vec2.x, vec2.y, 1.0f - vec2.x - vec2.y });
            }
        }

        if ((segment.m_verticesBuf.m_flags & VBUFFlags::Unknown1) != 0)
        {

            uint32_t inds;
            streamReader >> inds;

            uint8_t x = (uint8_t)(inds & 0xffu);
            uint8_t y = (uint8_t)((inds >> 8u) & 0xffu);
            uint8_t z = (uint8_t)((inds >> 16u) & 0xffu);

            segment.m_verticesBuf.m_boneIndices.push_back({ x, y, z });
        }

        if ((segment.m_verticesBuf.m_flags & VBUFFlags::Normal) != 0)
        {
            if ((segment.m_verticesBuf.m_flags & VBUFFlags::NormalCompressed) != 0)
            {
                int8_t data[4];
                streamReader >> data;
                Vector3<float> normal((float_t)data[0], (float_t)data[1], (float_t)data[2]);
                normal = (normal * 2.0f) - 1.0f;
                segment.m_verticesBuf.m_normals.push_back(normal);
            }
            else
            {
                Vector3<float> vec3;
                streamReader >> vec3;

                segment.m_verticesBuf.m_normals.push_back(vec3);
            }
        }

        if ((segment.m_verticesBuf.m_flags & VBUFFlags::Tangents) != 0)
        {
            if ((segment.m_verticesBuf.m_flags & VBUFFlags::NormalCompressed) != 0)
            {
                int8_t data[4];
                streamReader >> data;
                Vector3<float> tangent((float_t)data[0], (float_t)data[1], (float_t)data[2]);
                tangent = (tangent * 2.0f) - 1.0f;
                segment.m_verticesBuf.m_tangents.push_back(tangent);

                streamReader >> data;
                Vector3<float> biTangent((float_t)data[0], (float_t)data[1], (float_t)data[2]);
                biTangent = (biTangent * 2.0f) - 1.0f;
                segment.m_verticesBuf.m_biTangents.push_back(biTangent);
            }
            else
            {
                Vector3<float> vec3Tangent, vec3BiTangent;
                streamReader >> vec3Tangent >> vec3BiTangent;

                segment.m_verticesBuf.m_tangents.push_back(vec3Tangent);
                segment.m_verticesBuf.m_biTangents.push_back(vec3BiTangent);
            }
        }

        if ((segment.m_verticesBuf.m_flags & VBUFFlags::Color) != 0)
        {
            uint8_t colors[4];
            streamReader >> colors;

            godot::Color color{ (float)colors[0] / 255.0f, (float)colors[1] / 255.0f, (float)colors[2] / 255.0f, (float)colors[3] / 255.0f };
            segment.m_verticesBuf.m_colors.push_back(color);
        }

        if ((segment.m_verticesBuf.m_flags & VBUFFlags::StaticLighting) != 0)
        {
            uint8_t colors[4];
            streamReader >> colors;

            godot::Color color{ (float)colors[0] / 255.0f, (float)colors[1] / 255.0f, (float)colors[2] / 255.0f, (float)colors[3] / 255.0f };
            segment.m_verticesBuf.m_colors.push_back(color);
        }

        if ((segment.m_verticesBuf.m_flags & VBUFFlags::TexCoord) != 0)
        {
            if ((segment.m_verticesBuf.m_flags & VBUFFlags::TexCoordCompressed) != 0)
            {
                uint16_t data[2];
                streamReader >> data;
                Vector2<float> uv(data[0], data[1]);
                uv = uv / 2048.0f;
                segment.m_verticesBuf.m_texCoords.push_back(uv);
            }
            else
            {
                Vector2<float> vec2;
                streamReader >> vec2;

                segment.m_verticesBuf.m_texCoords.push_back(vec2);
            }
        }
    }
}
