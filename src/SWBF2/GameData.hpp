#pragma once

#include <godot_cpp/classes/node.hpp>

#include <lua.h>

#include "Native/Models/Model.hpp"
#include "Native/Texture/Texture.hpp"
#include "Native/Objects/ObjectDefinition.hpp"
#include "Native/Level.hpp"
#include "Native/SkyDome.hpp"
#include "Native/Light.hpp"
#include "Native/Terrain.hpp"
#include "Native/Scripting/Lua/LuaScript.hpp"

namespace SWBF2
{
    class GameData : public godot::Node {
        GDCLASS(GameData, godot::Node)

    private:
        static GameData *m_instance;

    public: // variables
        Native::SkyDome m_skyDome;
        Native::Terrain m_tern;

        std::unordered_map<uint8_t, PlayerTeam> m_teams;

        struct SGameData
        {
            std::unordered_map<Gamemode, Native::Level> m_levels;
            std::unordered_map<std::string, Native::World> m_worlds;
            std::unordered_map<std::string, Native::Light> m_lights;
            std::unordered_map<std::string, Native::Model> m_models;
            std::unordered_map<std::string, Native::Texture> m_tex;
            std::unordered_map<std::string, Native::ObjectDefinition> m_objectDefs;
            std::unordered_map<std::string, Native::Scripting::Lua::LuaScript> m_luaScripts;

            using LoclEntriesMap = std::unordered_map<FNVHash, std::u16string>;
            std::unordered_map<Language, LoclEntriesMap> m_locl;
        };

        std::unordered_map<std::string, SGameData> m_gameData;

    public: // methods
        GameData();
        ~GameData();

        static GameData *Instance();

        void ReadLevelFile(const std::string &file);
        const SGameData &GetMapData();
        void ClearMapData();

        void _ready() override;

    private:
        static void _bind_methods();
    };
}
