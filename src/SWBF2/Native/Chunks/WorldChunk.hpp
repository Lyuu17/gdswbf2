#pragma once

#include "StreamReader.hpp"

namespace SWBF2::Native
{
    class World;

    class WorldChunk {
    public:
        static void ProcessChunk(StreamReader &streamReader);

        static void ProcessWorldChunk(StreamReader &streamReader, World &world);
        static void ProcessInstChunk(StreamReader &streamReader, World &world);
    };

}
