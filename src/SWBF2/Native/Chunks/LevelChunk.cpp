#include <godot_cpp/variant/utility_functions.hpp>

#include "Native/Chunks/StreamReader.hpp"
#include "Native/Chunks/LevelChunk.hpp"
#include "Native/Chunks/WorldChunk.hpp"

#include "Native/SWBF2.hpp"

namespace SWBF2::Native
{
    void LevelChunk::ProcessChunk(StreamReader &streamReader)
    {
        Level lvl{};

        streamReader.SkipBytes(sizeof(uint32_t)); // hash?
        streamReader.SkipBytes(sizeof(uint32_t)); // lvl_ size left

        std::optional<StreamReader> readerChild;
        while ((readerChild = streamReader.ReadChild()).has_value())
        {
            switch (readerChild->GetHeader().m_Magic)
            {
                case "wrld"_m:
                {
                    World world{};

                    StreamReader r{ *readerChild };
                    WorldChunk::ProcessWorldChunk(r, world);

                    lvl.m_worlds.insert_or_assign(world.m_worldName, world);
                    break;
                }
                default:
                    godot::UtilityFunctions::printerr(__FILE__, ":", __LINE__, ": ", readerChild->GetHeader().ToString().c_str(), " not implemented");
                    break;
            }
        }

        const auto gamemodes = { "ctf", "conquest", "centerflag", "campaign", "tdm" };
        for (const auto &[id, world] : lvl.m_worlds)
        {
            std::string type = id.substr(id.find_first_of('_') + 1);

            if (std::find(gamemodes.begin(), gamemodes.end(), type) != gamemodes.end())
                SWBF2::m_levels.insert_or_assign(type, lvl);
        }
    }
}
