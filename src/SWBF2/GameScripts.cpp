
#include <godot_cpp/variant/utility_functions.hpp>

#include <lauxlib.h>

#include "Core.hpp"

#include "GameScripts.hpp"
#include "GameData.hpp"

namespace SWBF2
{
    GameScripts *GameScripts::m_instance = nullptr;

    GameScripts::GameScripts()
        : m_luaState(nullptr)
    {
        m_instance = this;
    }

    GameScripts::~GameScripts()
    {
        m_instance = nullptr;

        if (m_luaState)
            lua_close(m_luaState);
    }

    GameScripts *GameScripts::Instance()
    {
        return m_instance;
    }

    void GameScripts::_ready()
    {
        set_name("GameScripts");

        m_luaState = lua_open();

        GameData::Instance()->ReadLevelFile("shell.lvl");

        LoadScript("shell_interface");
    }

    void GameScripts::LoadScript(const std::string &scrName)
    {
        for (auto const &[filename, data] : GameData::Instance()->m_gameData)
        {
            for (auto const &[name, scr] : data.m_luaScripts)
            {
                if (scrName != name)
                    continue;

                int status = LoadScript(scr.m_name, scr.m_data);
                if (status > 0)
                {
                    if (status == LUA_ERRRUN)
                        throw std::runtime_error{ "error loading script " + scrName + ": LUA_ERRRUN" };
                    else if (status == LUA_ERRSYNTAX)
                        throw std::runtime_error{ "error loading script " + scrName + ": LUA_ERRSYNTAX" };
                    else if (status == LUA_ERRMEM)
                        throw std::runtime_error{ "error loading script " + scrName + ": LUA_ERRMEM" };
                    else
                        throw std::runtime_error{ "error loading script " + scrName + ": unknown error (" + std::to_string(status) + ")" };
                }

                return;
            }
        }
    }

    int GameScripts::LoadScript(const std::string &filename, const std::vector<std::byte> &data)
    {
        const char *charBuf = reinterpret_cast<const char *>(data.data());
        return lua_dobuffer(m_luaState, charBuf, data.size(), filename.c_str());
    }

    void GameScripts::RegisterCallback(const char *name, lua_CFunction func)
    {
        lua_pushcfunction(m_luaState, func);
        lua_pushstring(m_luaState, name);
        lua_insert(m_luaState, -2);
        lua_settable(m_luaState, -10001);
    }

    void GameScripts::_bind_methods()
    {
    }
}
