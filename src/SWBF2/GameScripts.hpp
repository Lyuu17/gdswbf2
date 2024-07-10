#pragma once

#include <godot_cpp/classes/node.hpp>

#include <lua.h>

#include "Native/Scripting/Lua/LuaScript.hpp"

namespace SWBF2
{
    class GameScripts : public godot::Node {
        GDCLASS(GameScripts, godot::Node)

    private:
        static GameScripts *m_instance;

    public: // variables
        lua_State *m_luaState;

    public: // methods
        GameScripts();
        ~GameScripts();

        static GameScripts *Instance();

        void LoadScript(const std::string &scr);
        int LoadScript(const std::string &filename, const std::vector<std::byte> &data);
        void RegisterCallback(const char *name, lua_CFunction func);

        void _ready() override;

    private:
        static void _bind_methods();
    };
}
