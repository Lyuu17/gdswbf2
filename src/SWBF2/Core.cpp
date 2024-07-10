
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/camera3d.hpp>

#include "Native/Chunks/ChunkProcessor.hpp"

#include "Core.hpp"
#include "Level.hpp"
#include "GameData.hpp"
#include "GameScripts.hpp"
#include "Version.h"

namespace SWBF2
{
    Core *Core::m_instance = nullptr;

    Core::Core()
        : m_curGamemode(Gamemode::NONE)
        , m_language(Language::ENGLISH)
        , m_platform("pc")
    {
        m_instance = this;
    }

    Core::~Core()
    {
        m_instance = nullptr;
    }

    Core *Core::Instance()
    {
        return m_instance;
    }

    void Core::_ready()
    {
        set_name("Core");

        GameData *gameData = memnew(GameData);
        add_child(gameData);
        gameData->ReadLevelFile("core.lvl");
        gameData->ReadLevelFile("common.lvl");
        gameData->set_owner(this);

        GameScripts *gameScripts = memnew(GameScripts);
        add_child(gameScripts);
        gameScripts->set_owner(this);

        godot::UtilityFunctions::print("hello world!");
    }

    void Core::LoadLevel(const godot::String &mapName)
    {
        if (mapName.is_empty())
        {
            remove_child(find_child("Level", false));

            GameData::Instance()->ClearMapData();

            m_curMapName = mapName;
            return;
        }

        m_curMapName = mapName;

        Level *lvl = memnew(Level);
        add_child(lvl);
        lvl->set_owner(this);
        lvl->LoadLevel(mapName);
    }

    void Core::_bind_methods()
    {
        godot::ClassDB::bind_method(godot::D_METHOD("get_mapname"), &Core::GetMapName);
        godot::ClassDB::bind_method(godot::D_METHOD("load_level", "mapname"), &Core::LoadLevel);

        godot::ClassDB::bind_method(godot::D_METHOD("get_language"), &Core::GetLanguage);
        godot::ClassDB::bind_method(godot::D_METHOD("set_language", "language"), &Core::SetLanguage);

        godot::ClassDB::bind_method(godot::D_METHOD("get_platform"), &Core::GetPlatform);

        std::string mapList;
        for (const auto &[mapId, mapPath] : DefaultGameMaps)
            mapList = std::format("{},{}", mapList, mapId);

        godot::ClassDB::add_property("Core", godot::PropertyInfo(godot::Variant::STRING, "mapname", godot::PROPERTY_HINT_ENUM, mapList.c_str()), "load_level", "get_mapname");
    }
}
