#pragma once

#include "Types.hpp"

#include "ChunkHeader.hpp"
#include "StreamReader.hpp"

#include "ModelChunk.hpp"
#include "UcfbChunk.hpp"
#include "WorldChunk.hpp"
#include "LoclChunk.hpp"
#include "TextureChunk.hpp"
#include "LevelChunk.hpp"
#include "SkyChunk.hpp"
#include "LightChunk.hpp"
#include "ObjectDefinitionChunk.hpp"
#include "TerrainChunk.hpp"
#include "ScriptChunk.hpp"

namespace SWBF2::Native
{
    using ChunkProcessingFunction = std::function<void(const std::string &filename, StreamReader &streamReader)>;

    class ChunkProcessor {
    public:
        static inline const std::unordered_map<uint32_t, ChunkProcessingFunction> m_functions
        {
            { "ucfb"_m, UcfbChunk::ProcessChunk },
            { "wrld"_m, WorldChunk::ProcessChunk },
            { "modl"_m, ModelChunk::ProcessChunk },
            { "Locl"_m, LoclChunk::ProcessChunk },
            { "tex_"_m, TextureChunk::ProcessChunk },
            { "lvl_"_m, LevelChunk::ProcessChunk },
            { "sky_"_m, SkyChunk::ProcessChunk },
            { "lght"_m, LightChunk::ProcessChunk },
            { "entc"_m, ObjectDefinitionChunk::ProcessChunk },
            { "tern"_m, TerrainChunk::ProcessChunk },
            { "scr_"_m, ScriptChunk::ProcessChunk }
        };

        static void ProcessChunk(const std::string &filename, StreamReader &streamReader, StreamReader &parentReader);
    };

}
