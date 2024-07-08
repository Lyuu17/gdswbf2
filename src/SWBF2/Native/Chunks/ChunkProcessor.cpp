#include <godot_cpp/variant/utility_functions.hpp>

#include "ChunkProcessor.hpp"

namespace SWBF2::Native
{
    void ChunkProcessor::ProcessChunk(const std::string &filename, StreamReader &streamReader, StreamReader &parentReader)
    {
        if (!m_functions.contains(streamReader.GetHeader().m_Magic))
        {
            godot::UtilityFunctions::printerr(__FILE__, ":", __LINE__, ": No processing function for ", streamReader.GetHeader().ToString().c_str(), ", keep reading...");
            return;
        }

        const auto &processor = m_functions.at(streamReader.GetHeader().m_Magic);
        processor(filename, streamReader);
    }
}
