
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

    enum class PrimitiveType : uint32_t {
        UNKNOWN,
        POINTLIST,
        LINELIST,
        LINESTRIP,
        TRIANGLELIST,
        TRIANGLESTRIP,
        TRIANGLEFAN
    };

    typedef struct _INDICES_BUF
    {
        uint32_t m_indicesCount;
        godot::PackedInt32Array m_indices;
    } IndicesBuf;

    typedef struct _VERTICES_BUF
    {
        uint32_t m_verticesCount;
        uint32_t m_stride; // bytes per vertex
        VBUFFlags m_flags;

        godot::PackedVector3Array m_positions;
        godot::PackedVector3Array m_normals;
        godot::PackedVector3Array m_tangents;
        godot::PackedVector3Array m_biTangents;

        godot::PackedColorArray m_colors;
        godot::PackedVector2Array m_texCoords;

        godot::PackedVector3Array m_boneIndices;
        godot::PackedVector3Array m_weights;
    } VerticesBuf;

    class ModelSegment {
    public:
        enum TextureType
        {
            TEXTURE_DEFAULT = 0,
            TEXTURE_NORMAL,
            TEXTURE_UNK3,
            TEXTURE_UNK4
        };

        PrimitiveType m_primitiveType;
        uint32_t m_vertexCount;
        uint32_t m_primitiveCount;
        Material m_material;
        std::string p_renderType; // TODO: enum?
        std::array<std::string, 4> m_textureNames;
        IndicesBuf m_indicesBuf;
        VerticesBuf m_verticesBuf;
        std::string m_parent;
        std::string m_tag;
    };
}
