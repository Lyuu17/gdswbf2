#pragma once

#include "StreamReader.hpp"

namespace SWBF2::Native
{
    class ScriptChunk {
    public:
        static void ProcessChunk(const std::string &filename, StreamReader &streamReader);
    };

}
