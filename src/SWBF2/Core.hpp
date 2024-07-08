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

namespace SWBF2
{
    class Core : public godot::Node {
        GDCLASS(Core, godot::Node)

    private:
        static Core *m_instance;

        godot::String m_curMapName;

    public: // variables
        lua_State *m_luaState;

        Native::SkyDome m_skyDome;

        Gamemode m_curGamemode;

        Native::Terrain m_tern;

        std::unordered_map<uint8_t, PlayerTeam> m_teams;

        std::unordered_map<Gamemode, Native::Level> m_levels;
        std::unordered_map<std::string, Native::World> m_worlds;
        std::unordered_map<std::string, Native::Light> m_lights;
        std::unordered_map<std::string, Native::Model> m_models;
        std::unordered_map<std::string, Native::Texture> m_tex;
        std::unordered_map<std::string, Native::ObjectDefinition> m_objectDefs;

        using LoclEntriesMap = std::unordered_map<FNVHash, std::u16string>;
        std::unordered_map<std::string, LoclEntriesMap> m_locl;

    public: // methods
        Core();
        ~Core();

        static Core *Instance();

        const godot::String &GetMapName() { return m_curMapName; };
        void LoadLevel(const godot::String &mapName);

        void _ready() override;

    private:
        static void _bind_methods();
    };
}
