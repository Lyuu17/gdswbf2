#pragma once

#include "ChunkHeader.hpp"

namespace SWBF2::Native
{
    class UcfbChunk {
    public:
        static void ReadUcfbFile(const std::string &filename);
        static void ProcessChunk(StreamReader &streamReader);
    };
}