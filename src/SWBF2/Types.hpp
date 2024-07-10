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
        { "cor1", "cor/cor1.lvl" },
        { "dag1", "dag/dag1.lvl" },
        { "dea1", "dea/dea1.lvl" },
        { "end1", "end/end1.lvl" },
        { "fel1", "fel/fel1.lvl" },
        { "geo1", "geo/geo1.lvl" },
        { "hot1", "hot/hot1.lvl" },
        { "kam1", "kam/kam1.lvl" },
        { "kas2", "kas/kas2.lvl" },
        { "mus1", "mus/mus1.lvl" },
        { "myg1", "myg/myg1.lvl" },
        { "nab2", "nab/nab2.lvl" },
        { "pol1", "pol/pol1.lvl" },
        { "tan1", "tan/tan1.lvl" },
        { "tat2", "tat/tat2.lvl" },
        { "tat3", "tat/tat3.lvl" },
        { "uta1", "uta/uta1.lvl" },
        { "yav1", "yav/yav1.lvl" }
    };

    enum class Language
    {
        ENGLISH = 0,
        SPANISH,
        ITALIAN,
        FRENCH,
        GERMAN,
        JAPANESE,
        UK_ENGLISH,
        THAI,
        POLISH
    };

    const static inline std::unordered_map<std::string_view, Language> DefaultLanguagesByName
    {
        { "english", Language::ENGLISH },
        { "spanish", Language::SPANISH },
        { "italian", Language::ITALIAN },
        { "french", Language::FRENCH },
        { "german", Language::GERMAN },
        { "japanese", Language::JAPANESE },
        { "uk_english", Language::UK_ENGLISH },
        { "thai", Language::THAI },
        { "polish", Language::POLISH }
    };

    const static inline std::unordered_map<Language, std::string_view> DefaultLanguages
    {
        { Language::ENGLISH, "english" },
        { Language::SPANISH, "spanish" },
        { Language::ITALIAN, "italian" },
        { Language::FRENCH, "french" },
        { Language::GERMAN, "german" },
        { Language::JAPANESE, "japanese" },
        { Language::UK_ENGLISH, "uk_english" },
        { Language::THAI, "thai" },
        { Language::POLISH, "polish" }
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
