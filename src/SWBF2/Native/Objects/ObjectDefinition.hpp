
#pragma once

namespace SWBF2::Native
{
    class ObjectDefinition {
    public:
        std::string m_classLabel;
        std::string m_geometryName;

        std::unordered_map<FNVHash, std::string> m_properties;
    };
}
