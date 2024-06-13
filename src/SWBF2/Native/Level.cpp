
#include "Level.hpp"

namespace SWBF2::Native
{
    World Level::m_world;

    std::unordered_map<std::string, Model> Level::m_models;
    std::unordered_map<std::string, std::unique_ptr<Texture>> Level::m_tex;
    std::unordered_map<std::string, Level::LoclEntriesMap> Level::m_locl;
}
