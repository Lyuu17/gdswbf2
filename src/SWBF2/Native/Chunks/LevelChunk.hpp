#pragma once

#include "StreamReader.hpp"

namespace SWBF2::Native
{
    class LevelChunk {
    public:
        static void ProcessChunk(const std::string &filename, StreamReader &streamReader);
    };

}
