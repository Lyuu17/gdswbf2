#pragma once

#include "StreamReader.hpp"
#include "ConfigReader.hpp"

namespace SWBF2::Native
{
    class SkyChunk {
    public:
        static void ProcessChunk(const std::string &filename, StreamReader &streamReader);
        static void ProcessDomeModels(const std::unique_ptr<ConfigNode> &node);
    };

}
