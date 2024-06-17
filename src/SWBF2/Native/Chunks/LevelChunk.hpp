#pragma once

#include "StreamReader.hpp"

namespace SWBF2::Native
{
    class LevelChunk {
    public:
        static void ProcessChunk(StreamReader &streamReader);
    };

}
