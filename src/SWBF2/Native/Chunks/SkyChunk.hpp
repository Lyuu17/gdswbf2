#pragma once

#include "StreamReader.hpp"

namespace SWBF2::Native
{
    class SkyChunk {
    public:
        static void ProcessChunk(StreamReader &streamReader);
    };

}
