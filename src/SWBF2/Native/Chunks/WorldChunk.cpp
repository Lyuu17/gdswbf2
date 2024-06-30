#include <godot_cpp/variant/utility_functions.hpp>

#include "Native/Chunks/StreamReader.hpp"
#include "Native/Chunks/WorldChunk.hpp"
#include "Native/Objects/GameObject.hpp"
#include "Native/SWBF2.hpp"

namespace SWBF2::Native
{
    void WorldChunk::ProcessChunk(StreamReader &streamReader)
    {
        World world{};

        ProcessWorldChunk(streamReader, world);

        SWBF2::m_worlds.insert_or_assign(world.m_worldName, world);
    }

    void WorldChunk::ProcessWorldChunk(StreamReader &streamReader, World &world)
    {
        auto nameReaderChild = streamReader.ReadChildWithHeader<"NAME"_m>();
        {
            *nameReaderChild >> world.m_worldName;
        }

        std::optional<StreamReader> readerChild;
        while ((readerChild = streamReader.ReadChild()).has_value())
        {
            switch (readerChild->GetHeader().m_Magic)
            {
                case "TNAM"_m:
                {
                    *readerChild >> world.m_terrainName;
                    break;
                }

                case "SNAM"_m:
                {
                    *readerChild >> world.m_skyName;
                    break;
                }

                case "inst"_m:
                {
                    StreamReader r{ *readerChild };
                    ProcessInstChunk(r, world);
                    break;
                }

                default:
                    break;
            }
        }
    }

    void WorldChunk::ProcessInstChunk(StreamReader &streamReader, World &world)
    {
        GameObject inst{};

        auto infoReaderChild = streamReader.ReadChildWithHeader<"INFO"_m>();
        {
            auto infoTypeReaderChild = infoReaderChild->ReadChildWithHeader<"TYPE"_m>();
            {
                std::u8string type;
                *infoTypeReaderChild >> type;

                inst.m_type = std::string(type.begin(), type.end());
            }

            auto infoNameReaderChild = infoReaderChild->ReadChildWithHeader<"NAME"_m>();
            {
                std::u8string name;
                *infoNameReaderChild >> name;

                inst.m_name = std::string(name.begin(), name.end());
            }

            auto infoXFRMReaderChild = infoReaderChild->ReadChildWithHeader<"XFRM"_m>();
            {
                *infoXFRMReaderChild >> inst.m_rotationMatrix;
                *infoXFRMReaderChild >> inst.m_position;
            }
        }

        std::optional<StreamReader> propReaderChild;
        while ((propReaderChild = streamReader.ReadChildWithHeader<"PROP"_m>()).has_value())
        {
            FNVHash prop;
            *propReaderChild >> prop;

            std::string value;
            *propReaderChild >> value;

            inst.m_properties.insert_or_assign(prop, value);
        }

        world.m_instances.push_back(inst);
    }
}
