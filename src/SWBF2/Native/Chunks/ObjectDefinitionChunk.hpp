#pragma once

#include "StreamReader.hpp"

namespace SWBF2::Native
{
    class ObjectDefinitionChunk {
    public:
        static void ProcessChunk(StreamReader &streamReader);
    };

}
