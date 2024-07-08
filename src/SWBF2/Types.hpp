#pragma once

#include <string>
#include <cstdint>
#include <unordered_map>
#include <string_view>
#include <functional>
#include <vector>
#include <optional>
#include <stdexcept>
#include <stdint.h>
#include <set>
#include <array>
#include <map>
#include <format>
#include <memory>

#include "FNVHash.hpp"
#include "Utils.hpp"

namespace SWBF2
{
    typedef uint32_t ChunkSize;
    typedef uint32_t FNVHash;
    typedef uint16_t SWBF2Handle;

    constexpr auto SWBF2HANDLE_INVALID = 0xffff;

    const static inline std::unordered_map<std::string_view, std::string_view> DefaultGameMaps
    {
        // name, path
        { "cor1", "cor/cor1" },
        { "dag1", "dag/dag1" },
        { "dea1", "dea/dea1" },
        { "end1", "end/end1" },
        { "fel1", "fel/fel1" },
        { "geo1", "geo/geo1" },
        { "hot1", "hot/hot1" },
        { "kam1", "kam/kam1" },
        { "kas2", "kas/kas2" },
        { "mus1", "mus/mus1" },
        { "myg1", "myg/myg1" },
        { "nab2", "nab/nab2" },
        { "pol1", "pol/pol1" },
        { "tan1", "tan/tan1" },
        { "tat2", "tat/tat2" },
        { "tat3", "tat/tat3" },
        { "uta1", "uta/uta1" },
        { "yav1", "yav/yav1" }
    };

    enum class Gamemode
    {
        NONE = 0,
        CTF,
        CONQUEST,
        CENTERFLAG,
        CAMPAIGN,
        TDM
    };

    enum TeamClassType : uint8_t
    {
        SOLDIER,
        ASSAULT,
        ENGINEER,
        SNIPER,
        OFFICIAL,
        SPECIAL
    };

    struct TeamClass
    {
        std::string model;
        uint8_t min;
        uint8_t max;
    };

    struct PlayerTeam
    {
        uint8_t team;
        uint8_t units;
        uint8_t reinforcements;
        std::unordered_map<TeamClassType, TeamClass> m_classes;
    };
}
