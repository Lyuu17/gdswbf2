#pragma once

#include "Native/Chunks/StreamReader.hpp"

#include "Native/Hashes.hpp"

namespace SWBF2::Native
{
    enum class ConfigDataType
    {
        FLOAT,
        STRING,
        FLOAT_VECTOR
    };

    class ConfigData {
    public:
        ConfigDataType m_dataType;

        float m_float;
        std::string m_string;
        std::vector<float> m_vecFloat;
    };

    class ConfigNode : public ConfigData {
    protected:
        std::unordered_multimap<FNVHash, std::unique_ptr<ConfigNode>> m_childs;
    public:
        ConfigNode &createNode(FNVHash hash) {
            auto it = m_childs.emplace(hash, std::make_unique<ConfigNode>());
            if (it == m_childs.end())
                throw std::runtime_error{ "failed to create node " };
            return *it->second;
        }

        auto &getNodes() {
            return m_childs;
        }
    };

    class ConfigReader : public StreamReader {
    public:
        ConfigReader(StreamReader &streamReader);

        std::string m_name;

        ConfigNode m_data;

    private:
        void ReadData(StreamReader &streamReader, ConfigNode &parentConfigNode);
        void ReadDataScop(StreamReader &streamReader, ConfigNode &parentConfigNode);
        void ReadDataElementInfo(StreamReader &streamReader, ConfigNode &parentConfigNode);
        void ReadDataElements(StreamReader &streamReader, ConfigNode &parentConfigNode, uint8_t count);
    };
}
