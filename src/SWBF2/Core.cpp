
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/camera3d.hpp>

#include "Native/Chunks/ChunkProcessor.hpp"

#include "Core.hpp"
#include "Level.hpp"
#include "Terrain.hpp"
#include "Version.h"

namespace SWBF2
{
    Core *Core::m_instance = nullptr;

    Core::Core()
        : m_curGamemode(Gamemode::NONE),
        m_luaState(nullptr)
    {
        m_instance = this;
    }

    Core::~Core()
    {
        m_instance = nullptr;

        if (m_luaState)
            lua_close(m_luaState);
    }

    Core *Core::Instance()
    {
        return m_instance;
    }

    void Core::_ready()
    {
        set_name("Core");

        m_luaState = lua_open();

        if (!Native::UcfbChunk::ReadUcfbFile("data/_lvl_pc/core.lvl"))
            throw std::runtime_error{ "failed to load core.lvl from game directory" };

        if (!Native::UcfbChunk::ReadUcfbFile("data/_lvl_pc/common.lvl"))
            throw std::runtime_error{ "failed to load common.lvl from game directory" };

        godot::UtilityFunctions::print("hello world!");
    }

    void Core::LoadLevel(const godot::String &mapName)
    {
        m_curMapName = mapName;

        if (mapName.is_empty())
        {
            remove_child(find_child("Level", false));
            remove_child(find_child("Terrain", false));

            // TODO reset
            return;
        }

        Native::UcfbChunk::ReadUcfbFile(std::format("data/_lvl_pc/{}.lvl", DefaultGameMaps.at(mapName.ascii().get_data())));

        Level *lvl = memnew(Level);
        add_child(lvl);
        lvl->set_owner(this);
        lvl->LoadLevel(mapName);

        Terrain *terr = memnew(Terrain);
        add_child(terr);
        terr->set_owner(this);
        terr->LoadTerrain();
    }

    void Core::_bind_methods()
    {
        godot::ClassDB::bind_method(godot::D_METHOD("get_mapname"), &Core::GetMapName);
        godot::ClassDB::bind_method(godot::D_METHOD("load_level", "mapname"), &Core::LoadLevel);

        std::string mapList;
        for (const auto &[mapId, mapPath] : DefaultGameMaps)
            mapList = std::format("{},{}", mapList, mapId);

        godot::ClassDB::add_property("Core", godot::PropertyInfo(godot::Variant::STRING, "mapname", godot::PROPERTY_HINT_ENUM, mapList.c_str()), "load_level", "get_mapname");
    }
}
