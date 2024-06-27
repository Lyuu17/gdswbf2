#pragma once

#include "StreamReader.hpp"

namespace SWBF2::Native
{
    class LightChunk {
    public:
        static void ProcessChunk(StreamReader &streamReader);
    };

}
