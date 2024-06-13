#pragma once

#include <algorithm>

namespace SWBF2
{
    inline void string_tolower(std::string &str)
    {
        std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::tolower(c); });
    }
}
