
#pragma once

#include "Types.hpp"

namespace SWBF2::Native
{
    // TODO?
    enum class FNVHash : uint32_t
    {
        TEXTURE = "Texture"_fnv,
        DOME_INFO = "DomeInfo"_fnv,
        DOME_MODEL = "DomeModel"_fnv,
    };

    extern const std::unordered_map<uint32_t, std::string_view> GameHashes;
}
