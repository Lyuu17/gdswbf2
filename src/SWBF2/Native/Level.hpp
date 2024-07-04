
#pragma once

#include "Models/Model.hpp"
#include "Texture/Texture.hpp"

#include "World.hpp"

namespace SWBF2::Native
{
    class Level {
    public:
        std::unordered_map<std::string, World> m_worlds;
        std::unordered_map<std::string, Model> m_models;
    };
}
