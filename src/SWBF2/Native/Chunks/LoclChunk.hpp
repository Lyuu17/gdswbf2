#pragma once

#include "ChunkHeader.hpp"

namespace SWBF2::Native
{
    class LoclChunk {
    public:
        static void ProcessChunk(const std::string &filename, StreamReader &streamReader);
        static void ReadLoclEntries(const std::string &filename, StreamReader &streamReader, const std::string &loclName);
    };
}
