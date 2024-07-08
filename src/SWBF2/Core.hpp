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

        Gamemode m_curGamemode;

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
