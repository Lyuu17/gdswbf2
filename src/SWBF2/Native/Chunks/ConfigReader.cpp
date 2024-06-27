/* Mostly code from swbf2-unmunge, as everything is */

#include <godot_cpp/variant/utility_functions.hpp>

#include "Native/Hashes.hpp"

#include "Native/Chunks/ConfigReader.hpp"

namespace SWBF2::Native
{
    ConfigReader::ConfigReader(StreamReader &streamReader)
        : m_nameHash(0), m_data({})
    {
        auto nameReaderChild = streamReader.ReadChildWithHeader<"NAME"_m>();

        if (nameReaderChild.has_value())
        {
            *nameReaderChild >> m_nameHash;
        }

        while (streamReader.IsNextHeader<"DATA"_m>())
        {
            ReadData(streamReader, m_data);
        }
    }

    void ConfigReader::ReadData(StreamReader &streamReader, ConfigNode &parentConfigNode)
    {
        auto dataReaderChild = streamReader.ReadChildWithHeader<"DATA"_m>();
        {
#pragma pack(push, 1)
            struct {
                FNVHash hash;
                uint8_t count;
            } data;
#pragma pack(pop)

            *dataReaderChild >> data;

            auto &node = parentConfigNode.createNode(data.hash);
            if (data.count > 0)
            {
                uint32_t stringSize;
                *dataReaderChild >> stringSize;

                dataReaderChild->SkipBytes(sizeof(FNVHash) * data.count);

                node.m_string.resize(stringSize);
                *dataReaderChild >> node.m_string;
            }

            auto scopReaderChild = streamReader.ReadChildWithHeader<"SCOP"_m>();
            {
                ReadDataScop(*scopReaderChild, node);
            }
        }
    }

    void ConfigReader::ReadDataScop(StreamReader &streamReader, ConfigNode &parentConfigNode)
    {
        while (streamReader.IsNextHeader<"DATA"_m>())
        {
            if (streamReader.IsNextHeader2<"DATA"_m, "SCOP"_m>())
            {
                ReadData(streamReader, parentConfigNode);

                continue;
            }

            auto scopDataReaderChild = streamReader.ReadChildWithHeader<"DATA"_m>();
            if (!scopDataReaderChild.has_value())
                throw std::runtime_error{ "wait, thats illegal" };

            StreamReader r{ *scopDataReaderChild };
            ReadDataElementInfo(r, parentConfigNode);
        }
    }

    void ConfigReader::ReadDataElementInfo(StreamReader &streamReader, ConfigNode &parentConfigNode)
    {
#pragma pack(push, 1)
        struct {
            FNVHash tag;
            uint8_t count;
        } data;
#pragma pack(pop)

        streamReader >> data;

        if (data.count > 0)
            ReadDataElements(streamReader, parentConfigNode.createNode(data.tag), data.count);
        else
            parentConfigNode.createNode(data.tag);
    }

    void ConfigReader::ReadDataElements(StreamReader &streamReader, ConfigNode &parentConfigNode, uint8_t count)
    {
        float floatValue;
        streamReader >> floatValue;

        if (count == 1)
        {
            uint32_t stringSize;
            streamReader >> stringSize;

            if (stringSize > 0)
            {
                parentConfigNode.m_dataType = ConfigDataType::STRING;

                streamReader >> parentConfigNode.m_string;
            }
            else
            {
                parentConfigNode.m_dataType = ConfigDataType::FLOAT;
                parentConfigNode.m_float = floatValue;
            }
        }
        else
        {
            parentConfigNode.m_dataType = ConfigDataType::FLOAT_VECTOR;
            parentConfigNode.m_vecFloat.push_back(floatValue);

            for (int i = 1; i < count; i++)
            {
                float elementValue;
                streamReader >> elementValue;

                parentConfigNode.m_vecFloat.push_back(elementValue);
            }
        }
    }
}
