#pragma once

#include "StreamReader.hpp"

namespace SWBF2::Native
{
    class UcfbChunk {
    public:
        static bool ReadUcfbFile(const std::string &root, const std::string &filename);
        static void ProcessChunk(const std::string &filename, StreamReader &streamReader);
    };
}
