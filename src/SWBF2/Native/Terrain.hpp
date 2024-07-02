
#pragma once

namespace SWBF2::Native
{
    struct TerrainGeometryVBufEntry {
        godot::Vector3 position;
        godot::Vector3 normal;
        uint32_t colour;
    };

    struct TerrainTextureVBufExtraEntry {
        godot::Vector3 position;
        std::byte unknown_0[3];
        std::uint8_t texture_value;
    };

    struct TerrainTextureVBufEntry {
        std::uint16_t x;
        std::uint16_t y;
        std::uint16_t z;
        std::uint16_t unknown_0;

        std::uint8_t unknown_1;
        std::uint8_t texture_value_0;
        std::uint8_t unknown_2;
        std::uint8_t texture_value_1;

        std::uint32_t colour;
    };

    struct TerrainPatch
    {
        struct
        {
            std::vector<TerrainGeometryVBufEntry> m_geometry;
            std::vector<TerrainTextureVBufEntry> m_textures;
            std::vector<TerrainTextureVBufExtraEntry> m_texturesExtra;
        } m_vertices;

        struct
        {
            std::vector<uint16_t> m_geometry;
            std::vector<uint16_t> m_textureExtra;
        } m_indices;
    };

    class Terrain {
    public:
        constexpr static auto MaxTextures = 16u;

        enum class RenderTypes : std::int16_t
        {
            NONE = 0,
            SOLID_COLOUR = 4,
            NORMAL = 15
        };

        struct PatchInfo {
            RenderTypes render_type;
            uint8_t water_layer;
            uint8_t unknown;
        };

        std::string m_name;

        float m_gridUnitSize;
        float m_heightScale;
        float m_heightFloor;
        float m_heightCeiling;
        uint16_t m_gridSize;
        uint16_t m_heightPatches;
        uint16_t m_texturePatches;
        uint16_t m_textureCount;
        uint16_t m_maxTextureLayers;
        uint16_t m_unknown;

        std::vector<std::string> m_textures;
        std::string m_detailTexture;
        std::vector<float> m_textureScales;
        std::vector<uint8_t> m_textureAxis;
        std::vector<float> m_textureRotn;

        std::vector<TerrainPatch> m_patches;
    };
}
