#include <godot_cpp/variant/utility_functions.hpp>

#include "Native/Chunks/StreamReader.hpp"
#include "Native/Chunks/WorldChunk.hpp"
#include "Native/Level.hpp"

#include "Native/Instance.hpp"

namespace SWBF2::Native
{
    void WorldChunk::ProcessChunk(StreamReader &streamReader)
    {
        auto nameReaderChild = streamReader.ReadChildWithHeader<"NAME"_m>();
        {
            *nameReaderChild >> Level::m_world.m_worldName;
        }

        std::optional<StreamReader> readerChild;
        while ((readerChild = streamReader.ReadChild()).has_value())
        {
            switch (readerChild->GetHeader().m_Magic)
            {
                case "TNAM"_m:
                {
                    *readerChild >> Level::m_world.m_terrainName;
                    break;
                }

                case "SNAM"_m:
                {
                    *readerChild >> Level::m_world.m_skyName;
                    break;
                }

                case "inst"_m:
                {
                    StreamReader r{ *readerChild };
                    ProcessInstChunk(r);
                    break;
                }

                default:
                    break;
            }
        }
    }

    void WorldChunk::ProcessInstChunk(StreamReader &streamReader)
    {
        Instance inst{};

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
            uint32_t prop;
            *propReaderChild >> prop;

            std::string value;
            *propReaderChild >> value;

            inst.m_properties.insert_or_assign(prop, value);
        }

        Level::m_world.m_instances.push_back(inst);
    }
}
