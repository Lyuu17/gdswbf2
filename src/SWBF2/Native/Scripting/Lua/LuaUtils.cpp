
#include <lua.h>

#include "Core.hpp"
#include "GameScripts.hpp"

#include "LuaUtils.hpp"

namespace SWBF2::Native::Scripting::Lua
{
    namespace LuaUtils
    {
        void PushUString(const std::u16string &str)
        {
            const char *s = reinterpret_cast<const char *>(str.data());
            lua_pushlstring(GameScripts::Instance()->m_luaState, s, 2 * str.size() + 2);
        }
    }
}
