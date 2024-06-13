
#pragma once

#include "Types.hpp"

#include "Material.hpp"

namespace SWBF2::Native
{
    enum VBUFFlags : uint32_t
    {
        None = 0b0u,
        Position = 0b10u,
        Unknown1 = 0b100u,		// definetly not bone indices

        // this is questionable... not found in all of sides/rep.lvl. Another UV maybe (2 float)?
        BlendWeight = 0b1000u,

        Normal = 0b100000u,
        Tangents = 0b1000000u,
        Color = 0b10000000u,
        StaticLighting = 0b100000000u,
        TexCoord = 0b1000000000u,

        PositionCompressed = 0b1000000000000u,
        BlendWeightCompressed = 0b10000000000000u,
        NormalCompressed = 0b100000000000000u,
        TexCoordCompressed = 0b1000000000000000u
    };

    typedef struct _MODEL_SEGMENT_INFO
    {
        Topology m_topology;
        uint32_t m_vertexCount;
        uint32_t m_primitiveCount;
    } ModelSegmentInfo;

    typedef struct _INDICES_BUF
    {
        uint32_t m_indicesCount;
        std::vector<uint16_t> m_indices;
    } IndicesBuf;

    typedef struct _VERTICES_BUF
    {
        uint32_t m_verticesCount;
        uint32_t m_stride; // bytes per vertex
        VBUFFlags m_flags;

        std::vector<Vector3<float>> m_positions;
        std::vector<Vector3<float>> m_normals;
        std::vector<Vector3<float>> m_tangents;
        std::vector<Vector3<float>> m_biTangents;

        std::vector<RGBA> m_colors;
        std::vector<Vector2<float>> m_texCoords;

        std::vector<Vector3<uint8_t>> m_boneIndices;
        std::vector<Vector3<float>> m_weights;
    } VerticesBuf;

    class ModelSegment {
    public:
        ModelSegmentInfo m_info;

        Material m_material;
        std::string p_renderType; // TODO: enum?
        std::vector<std::string> m_textureNames;
        IndicesBuf m_indicesBuf;
        VerticesBuf m_verticesBuf;
        std::string m_parent;
        std::string m_tag;
    };
}
