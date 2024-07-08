#pragma once

#include "StreamReader.hpp"

namespace SWBF2::Native
{
    class Terrain;

    class TerrainChunk {
    public:
        static void ProcessChunk(const std::string &filename, StreamReader &streamReader);
        static void ReadPatches(StreamReader &streamReader, Terrain &tern);
        static void ReadPatch(StreamReader &streamReader, Terrain &tern);
    };

}
