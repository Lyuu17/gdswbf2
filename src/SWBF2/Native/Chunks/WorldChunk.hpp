#pragma once

#include "StreamReader.hpp"

namespace SWBF2::Native
{
    class WorldChunk {
    public:
        static void ProcessChunk(StreamReader &streamReader);

        static void ProcessInstChunk(StreamReader &streamReader);
    };

}
