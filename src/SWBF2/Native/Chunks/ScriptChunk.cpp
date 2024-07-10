#include <godot_cpp/variant/utility_functions.hpp>

#include "Native/Chunks/StreamReader.hpp"
#include "Native/Chunks/ScriptChunk.hpp"
#include "Native/Scripting/Lua/LuaScript.hpp"

#include "GameData.hpp"

namespace SWBF2::Native
{
    void ScriptChunk::ProcessChunk(const std::string &filename, StreamReader &streamReader)
    {
        Scripting::Lua::LuaScript luaScript{};

        auto nameReaderChild = streamReader.ReadChildWithHeader<"NAME"_m>();
        {
            *nameReaderChild >> luaScript.m_name;
        }

        [[maybe_unused]] auto infoReaderChild = streamReader.ReadChildWithHeader<"INFO"_m>();
        {}

        auto bodyReaderChild = streamReader.ReadChildWithHeader<"BODY"_m>();
        {
            luaScript.m_data.resize(bodyReaderChild->GetHeader().size);
            *bodyReaderChild >> luaScript.m_data;
        }

        GameData::Instance()->m_gameData[filename].m_luaScripts.insert_or_assign(luaScript.m_name, luaScript);
    }
}
