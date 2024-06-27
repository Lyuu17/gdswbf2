/* Mostly code from swbf2-unmunge, as everything is */

#include <godot_cpp/variant/utility_functions.hpp>

#include "Native/Hashes.hpp"

#include "Native/Chunks/ConfigReader.hpp"

namespace SWBF2::Native
{
    ConfigReader::ConfigReader(StreamReader &streamReader)
        : m_data({})
    {
        auto nameReaderChild = streamReader.ReadChildWithHeader<"NAME"_m>();

        if (nameReaderChild.has_value())
        {
            uint32_t nameHash;
            *nameReaderChild >> nameHash;

            m_name = GameHashes.contains(nameHash) ? GameHashes.at(nameHash) : "unknown";
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
            FNVHash hash;
            *dataReaderChild >> hash;

            auto scopReaderChild = streamReader.ReadChildWithHeader<"SCOP"_m>();
            {
                ReadDataScop(*scopReaderChild, parentConfigNode.createNode(hash));
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
    }

    void ConfigReader::ReadDataElements(StreamReader &streamReader, ConfigNode &parentConfigNode, uint8_t count)
    {
#pragma pack(push, 1)
        struct
        {
            float floatValue;
            uint32_t stringSize;
        } data_element;
#pragma pack(pop)

        streamReader >> data_element;

        if (count == 1)
        {
            if (data_element.stringSize > 0)
            {
                parentConfigNode.m_dataType = ConfigDataType::STRING;

                streamReader >> parentConfigNode.m_string;
            }
            else
            {
                parentConfigNode.m_dataType = ConfigDataType::FLOAT;
                parentConfigNode.m_float = data_element.floatValue;
            }
        }
        else
        {
            parentConfigNode.m_dataType = ConfigDataType::FLOAT_VECTOR;
            parentConfigNode.m_vecFloat.push_back(data_element.floatValue);

            for (int i = 1; i < count; i++)
            {
                float elementValue;
                streamReader >> elementValue;

                parentConfigNode.m_dataType = ConfigDataType::FLOAT_VECTOR;
                parentConfigNode.m_vecFloat.push_back(elementValue);
            }
        }
    }
}
