
#pragma once

#include "Models/Model.hpp"
#include "Texture/Texture.hpp"

#include "World.hpp"

namespace SWBF2::Native
{
    struct DomeModel
    {
        std::string m_geometry;
    };

    class SkyDome {
    public:
        std::string m_texture;

        std::vector<DomeModel> m_domeModels;
    };
}
