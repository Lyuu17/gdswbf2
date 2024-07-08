
#include <godot_cpp/variant/utility_functions.hpp>

#include "Native/Chunks/ChunkProcessor.hpp"

#include "Core.hpp"

#include "GameData.hpp"

namespace SWBF2
{
    GameData *GameData::m_instance = nullptr;

    GameData::GameData()
    {
        m_instance = this;
    }

    GameData::~GameData()
    {
        m_instance = nullptr;
    }

    GameData *GameData::Instance()
    {
        return m_instance;
    }

    void GameData::_ready()
    {
        set_name("GameData");
    }

    void GameData::ReadLevelFile(const std::string &file)
    {
        constexpr auto rootPath = "data/_lvl_pc/";
        if (!Native::UcfbChunk::ReadUcfbFile(rootPath, file))
            throw std::runtime_error{ "failed to load " + (rootPath + file) + " from game directory" };
    }

    const GameData::SGameData &GameData::GetMapData()
    {
        std::string mapPath{ DefaultGameMaps.at(Core::Instance()->GetMapName().ascii().get_data()) };
        return m_gameData[mapPath];
    }

    void GameData::ClearMapData()
    {
        std::string mapPath{ DefaultGameMaps.at(Core::Instance()->GetMapName().ascii().get_data()) };
        m_gameData[mapPath] = {};
    }

    void GameData::_bind_methods()
    {
    }
}
