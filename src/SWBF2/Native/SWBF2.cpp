
#include "Native/Chunks/UcfbChunk.hpp"

#include "SWBF2.hpp"

namespace SWBF2::Native
{
    SkyDome SWBF2::m_skyDome;

    std::string SWBF2::m_curMapName;
    LevelGamemode SWBF2::m_curLevel;

    std::unordered_map<LevelGamemode, Level> SWBF2::m_levels;
    std::unordered_map<std::string, World> SWBF2::m_worlds;
    std::unordered_map<std::string, Light> SWBF2::m_lights;
    std::unordered_map<std::string, Model> SWBF2::m_models;
    std::unordered_map<std::string, Texture> SWBF2::m_tex;
    std::unordered_map<std::string, ObjectDefinition> SWBF2::m_objectDefs;
    std::unordered_map<std::string, SWBF2::LoclEntriesMap> SWBF2::m_locl;

    void SWBF2::Init()
    {
        if (!UcfbChunk::ReadUcfbFile("data/_lvl_pc/core.lvl"))
            throw std::runtime_error{ "failed to load core.lvl from game directory" };

        if (!UcfbChunk::ReadUcfbFile("data/_lvl_pc/common.lvl"))
            throw std::runtime_error{ "failed to load common.lvl from game directory" };
    }

    void SWBF2::Reset()
    {
        m_skyDome = {};
        m_curMapName = {};
        m_curLevel = {};

        m_levels.clear();
        m_worlds.clear();
        m_lights.clear();
        m_models.clear();
        m_tex.clear();
        m_locl.clear();
    }

    bool SWBF2::LoadLevelFile(const std::string &levelname)
    {
        m_curMapName = levelname;

        return UcfbChunk::ReadUcfbFile(std::format("data/_lvl_pc/{}.lvl", DefaultGameMaps.at(levelname)));
    }

    void SWBF2::LoadGamemode(LevelGamemode gamemode)
    {
        m_curLevel = gamemode;
    }

    const Level &SWBF2::GetLevel()
    {
        if (!m_levels.contains(m_curLevel))
            throw std::runtime_error{ "failed to get an unknown level " };
        return m_levels.at(m_curLevel);
    }
}
