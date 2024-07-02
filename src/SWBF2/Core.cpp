
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/camera3d.hpp>

#include "Native/Chunks/ChunkProcessor.hpp"
#include "Native/SWBF2.hpp"

#include "Core.hpp"
#include "Level.hpp"
#include "Terrain.hpp"
#include "Version.h"

namespace SWBF2
{
    Core::Core()
    {
    }

    void Core::_ready()
    {
        set_name("Core");

        godot::UtilityFunctions::print("hello world!");
    }

    void Core::LoadLevel(const godot::String &mapName)
    {
        m_curMapName = mapName;

        if (mapName.is_empty())
        {
            remove_child(find_child("Level", false));
            remove_child(find_child("Terrain", false));

            SWBF2::Native::SWBF2::Reset();
            return;
        }

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
        for (const auto &[mapId, mapPath] : SWBF2::Native::DefaultGameMaps)
            mapList = std::format("{},{}", mapList, mapId);

        godot::ClassDB::add_property("Core", godot::PropertyInfo(godot::Variant::STRING, "mapname", godot::PROPERTY_HINT_ENUM, mapList.c_str()), "load_level", "get_mapname");
    }
}
