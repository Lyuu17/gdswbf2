
#pragma once

#include "Native/Models/Model.hpp"
#include "Native/Texture/Texture.hpp"
#include "Native/Level.hpp"
#include "Native/SkyDome.hpp"
#include "Native/Light.hpp"

namespace SWBF2::Native
{
    const static inline std::unordered_map<std::string_view, std::string_view> DefaultGameMaps
    {
        // name, path
        { "cor1", "cor/cor1" },
        { "yav1", "yav/yav1" }
    };

    enum class LevelGamemode
    {
        NONE = 0,
        CTF,
        CONQUEST,
        CENTERFLAG,
        CAMPAIGN,
        TDM
    };

    class SWBF2 {
    public:
        static SkyDome m_skyDome;

        static std::string m_curMapName;
        static LevelGamemode m_curLevel;

        static std::unordered_map<LevelGamemode, Level> m_levels;
        static std::unordered_map<std::string, World> m_worlds;
        static std::unordered_map<std::string, Light> m_lights;
        static std::unordered_map<std::string, Model> m_models;
        static std::unordered_map<std::string, Texture> m_tex;

        using LoclEntriesMap = std::unordered_map<FNVHash, std::u16string>;
        static std::unordered_map<std::string, LoclEntriesMap> m_locl;

        static void Init();
        static void Reset();
        static bool LoadLevelFile(const std::string &levelname);
        static void LoadGamemode(LevelGamemode gamemode);
        static const Level &GetLevel();
    };
}
