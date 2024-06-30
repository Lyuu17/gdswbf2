#include <godot_cpp/variant/utility_functions.hpp>

#include "Native/Chunks/StreamReader.hpp"
#include "Native/Chunks/LevelChunk.hpp"
#include "Native/Chunks/WorldChunk.hpp"

#include "Native/Hashes.hpp"
#include "Native/SWBF2.hpp"

namespace SWBF2::Native
{
    void LevelChunk::ProcessChunk(StreamReader &streamReader)
    {
        Level lvl{};

        FNVHash hash;
        streamReader >> hash;

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

        const static std::unordered_map<LevelGamemode, std::string_view> LevelGamemodesStr
        {
            { LevelGamemode::CTF, "ctf" },
            { LevelGamemode::CONQUEST, "conquest" },
            { LevelGamemode::CENTERFLAG, "centerflag" },
            { LevelGamemode::CAMPAIGN, "campaign" },
            { LevelGamemode::TDM, "tdm" }
        };

        for (const auto &[id, str] : LevelGamemodesStr)
        {
            if (FNVGenerateHash(std::format("{}_{}", SWBF2::m_curMapName, str)) == hash)
            {
                SWBF2::m_levels.insert_or_assign(id, lvl);
                break;
            }
        }
    }
}
