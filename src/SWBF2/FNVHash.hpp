#pragma once

namespace SWBF2
{
    typedef uint32_t FNVHash;

    constexpr FNVHash FNVGenerateHash(const std::string &str)
    {
        constexpr uint32_t FNV_prime = 16777619;
        constexpr uint32_t offset_basis = 2166136261;

        uint32_t hash = offset_basis;

        const char *buffer = str.data();
        for (size_t i = 0; i < str.length(); ++i)
        {
            char c = buffer[i];
            c |= 0x20;

            hash ^= c;
            hash *= FNV_prime;
        }

        return hash;
    }

    constexpr FNVHash operator""_fnv(const char *str, const std::size_t length)
    {
        return FNVGenerateHash({ str, length });
    }
}
