
#include <iostream>
#include <fstream>

#include <godot_cpp/variant/utility_functions.hpp>

#include "StreamReader.hpp"
#include "ChunkProcessor.hpp"

#include "UcfbChunk.hpp"

namespace SWBF2::Native
{
    bool UcfbChunk::ReadUcfbFile(const std::string &root, const std::string &filename)
    {
        std::ifstream is{ root + filename,std::ios::binary | std::ios::ate };
        if (!is.is_open())
        {
            godot::UtilityFunctions::printerr(__FILE__, ":", __LINE__, ": failed open ", filename.c_str(), " file");
            return false;
        }

        auto size = is.tellg();
        std::vector<std::byte> bytes;
        bytes.resize(size);

        godot::UtilityFunctions::print(__FILE__, ":", __LINE__, ": Reading ", size, " bytes of ", filename.c_str(), " file");

        is.seekg(0, std::ios::beg);
        is.read(reinterpret_cast<char *>(&bytes[0]), size);
        is.close();

        StreamReader streamReader{ bytes };
        ProcessChunk(filename, streamReader);

        godot::UtilityFunctions::print(__FILE__, ":", __LINE__, ": Finished reading ", bytes.size(), " bytes of ", filename.c_str(), " file");

        return true;
    }

    void UcfbChunk::ProcessChunk(const std::string &filename, StreamReader &streamReader)
    {
        godot::UtilityFunctions::print(__FILE__, ":", __LINE__, ": Processing chunk ", streamReader.GetHeader().ToString().c_str(), " with size ", streamReader.GetHeader().size, ", eof ", streamReader.IsEof());

        std::vector<std::pair<StreamReader, StreamReader>> children_parents;
        children_parents.reserve(64);

        while (!streamReader.IsEof()) {
            auto streamReaderChild = streamReader.ReadChild();
            if (streamReaderChild)
                children_parents.emplace_back(*streamReaderChild, streamReader);
        }

        for (auto &[reader1, reader2] : children_parents) {
            ChunkProcessor::ProcessChunk(filename, reader1, reader2);
        }
    }
}
