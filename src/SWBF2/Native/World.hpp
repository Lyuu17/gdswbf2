
#pragma once

#include "Instance.hpp"

namespace SWBF2::Native
{
    class World {
    public:
        std::string m_worldName;
        std::string m_terrainName;
        std::string m_skyName;

        std::vector<Instance> m_instances;
    };
}
