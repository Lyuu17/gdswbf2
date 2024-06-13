
#pragma once

#include "Models/Model.hpp"
#include "Texture/Texture.hpp"

#include "World.hpp"

namespace SWBF2::Native
{
    class Level {
    public:
        static World m_world;

        static std::unordered_map<std::string, Model> m_models;
        static std::unordered_map<std::string, std::unique_ptr<Texture>> m_tex;

        using LoclEntriesMap = std::unordered_map<FNVHash, std::u16string>;
        static std::unordered_map<std::string, LoclEntriesMap> m_locl;
    };
}
