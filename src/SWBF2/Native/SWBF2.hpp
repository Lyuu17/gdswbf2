
#pragma once

#include <lua.h>

#include "Native/Models/Model.hpp"
#include "Native/Texture/Texture.hpp"
#include "Native/Objects/ObjectDefinition.hpp"
#include "Native/Level.hpp"
#include "Native/SkyDome.hpp"
#include "Native/Light.hpp"
#include "Native/Terrain.hpp"

namespace SWBF2::Native
{
    const static inline std::unordered_map<std::string_view, std::string_view> DefaultGameMaps
    {
        // name, path
        { "cor1", "cor/cor1" },
        { "dag1", "dag/dag1" },
        { "dea1", "dea/dea1" },
        { "end1", "end/end1" },
        { "fel1", "fel/fel1" },
        { "geo1", "geo/geo1" },
        { "hot1", "hot/hot1" },
        { "kam1", "kam/kam1" },
        { "kas2", "kas/kas2" },
        { "mus1", "mus/mus1" },
        { "myg1", "myg/myg1" },
        { "nab2", "nab/nab2" },
        { "pol1", "pol/pol1" },
        { "tan1", "tan/tan1" },
        { "tat2", "tat/tat2" },
        { "tat3", "tat/tat3" },
        { "uta1", "uta/uta1" },
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
        enum TeamClassType : uint8_t
        {
            SOLDIER,
            ASSAULT,
            ENGINEER,
            SNIPER,
            OFFICIAL,
            SPECIAL
        };

        struct TeamClass
        {
            std::string model;
            uint8_t min;
            uint8_t max;
        };

        struct Team
        {
            uint8_t team;
            uint8_t units;
            uint8_t reinforcements;
            std::unordered_map<TeamClassType, TeamClass> m_classes;
        };

        static lua_State *m_luaState;

        static SkyDome m_skyDome;

        static std::string m_curMapName;
        static LevelGamemode m_curLevel;

        static Terrain m_tern;

        static std::unordered_map<uint8_t, Team> m_teams;

        static std::unordered_map<LevelGamemode, Level> m_levels;
        static std::unordered_map<std::string, World> m_worlds;
        static std::unordered_map<std::string, Light> m_lights;
        static std::unordered_map<std::string, Model> m_models;
        static std::unordered_map<std::string, Texture> m_tex;
        static std::unordered_map<std::string, ObjectDefinition> m_objectDefs;

        using LoclEntriesMap = std::unordered_map<FNVHash, std::u16string>;
        static std::unordered_map<std::string, LoclEntriesMap> m_locl;

        static void Init();
        static void Reset();
        static bool LoadLevelFile(const std::string &levelname);
        static void LoadGamemode(LevelGamemode gamemode);
        static const Level &GetLevel();
    };
}
