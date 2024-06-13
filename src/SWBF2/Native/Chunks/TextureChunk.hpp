#pragma once

#include "Native/Chunks/StreamReader.hpp"

#include "Native/Texture/Texture.hpp"

namespace SWBF2::Native
{
    class TextureChunk {
    public:
        static void ProcessChunk(StreamReader &streamReader);
        static void ProcessFMTChunk(StreamReader &streamReader, Texture *tex);
        static void ProcessTextureLevelChunk(StreamReader &streamReader, TextureFormat &fmt);
    };

}
