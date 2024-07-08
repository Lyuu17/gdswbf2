#include <godot_cpp/variant/utility_functions.hpp>

#include "Native/Chunks/StreamReader.hpp"
#include "Native/Chunks/LevelChunk.hpp"
#include "Native/Chunks/WorldChunk.hpp"
#include "Native/Chunks/ModelChunk.hpp"
#include "Native/Hashes.hpp"

#include "Core.hpp"

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
                case "modl"_m:
                {
                    Model mdl{};

                    StreamReader r{ *readerChild };
                    ModelChunk::ProcessChunkOut(r, mdl);

                    lvl.m_models.insert_or_assign(mdl.m_name, mdl);

                    break;
                }
                default:
                    godot::UtilityFunctions::printerr(__FILE__, ":", __LINE__, ": ", readerChild->GetHeader().ToString().c_str(), " not implemented");
                    break;
            }
        }

        const static std::unordered_map<Gamemode, std::string_view> LevelGamemodesStr
        {
            { Gamemode::CTF, "ctf" },
            { Gamemode::CONQUEST, "conquest" },
            { Gamemode::CENTERFLAG, "centerflag" },
            { Gamemode::CAMPAIGN, "campaign" },
            { Gamemode::TDM, "tdm" }
        };

        for (const auto &[id, str] : LevelGamemodesStr)
        {
            if (FNVGenerateHash(std::format("{}_{}", Core::Instance()->GetMapName().ascii().get_data(), str)) == hash)
            {
                Core::Instance()->m_levels.insert_or_assign(id, lvl);
                break;
            }
        }
    }
}
