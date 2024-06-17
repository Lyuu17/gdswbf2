
#pragma once

#include "Native/Models/Model.hpp"
#include "Native/Texture/Texture.hpp"
#include "Native/Level.hpp"

namespace SWBF2::Native
{
    class SWBF2 {
    public:
        static std::string m_curLevel;

        static std::unordered_map<std::string, Level> m_levels;
        static std::unordered_map<std::string, World> m_worlds;

        static std::unordered_map<std::string, Model> m_models;
        static std::unordered_map<std::string, Texture> m_tex;

        using LoclEntriesMap = std::unordered_map<FNVHash, std::u16string>;
        static std::unordered_map<std::string, LoclEntriesMap> m_locl;

        static void LoadLevelWithGamemode(const std::string &lvlfile, const std::string &gamemode);
        static const Level &GetLevel();
    };
}
