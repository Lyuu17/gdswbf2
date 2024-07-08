
#pragma once

#include <lua.h>

namespace SWBF2::Native::Scripting::Lua
{
    class LuaCallbacks {
    public:
        static void Init();
        static void RegisterCallback(const char *name, lua_CFunction func);
    };
}
