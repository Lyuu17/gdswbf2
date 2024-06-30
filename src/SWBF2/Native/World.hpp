
#pragma once

#include "GameObject.hpp"

namespace SWBF2::Native
{
    class World {
    public:
        std::string m_worldName;
        std::string m_terrainName;
        std::string m_skyName;

        std::vector<GameObject> m_instances;
    };
}
