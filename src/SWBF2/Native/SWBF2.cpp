
#include "Native/Chunks/UcfbChunk.hpp"

#include "SWBF2.hpp"

namespace SWBF2::Native
{
    SkyDome SWBF2::m_skyDome;

    std::string SWBF2::m_curLevel;

    std::unordered_map<std::string, Level> SWBF2::m_levels;
    std::unordered_map<std::string, World> SWBF2::m_worlds;
    std::unordered_map<std::string, Model> SWBF2::m_models;
    std::unordered_map<std::string, Texture> SWBF2::m_tex;
    std::unordered_map<std::string, SWBF2::LoclEntriesMap> SWBF2::m_locl;

    bool SWBF2::LoadLevelWithGamemode(const std::string &lvlfile, const std::string &lvl)
    {
        bool ret = UcfbChunk::ReadUcfbFile(std::format("data/_lvl_pc/{}.lvl", lvlfile));

        m_curLevel = lvl;

        return ret;
    }

    const Level &SWBF2::GetLevel()
    {
        if (!m_levels.contains(m_curLevel))
            throw std::runtime_error{ "failed to get an unknown level " };
        return m_levels.at(m_curLevel);
    }
}
