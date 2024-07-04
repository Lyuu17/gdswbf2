#pragma once

#include "StreamReader.hpp"

#include "Native/Models/Model.hpp"

namespace SWBF2::Native
{
    class ModelChunk {
    public:
        static void ProcessChunk(StreamReader &streamReader);
        static void ProcessChunkOut(StreamReader &streamReader, Model &mdl);
        static void ProcessSegmentChunk(StreamReader &streamReader, Model &model);
        static void ProcessSegmentVerticesBuffer(StreamReader &streamReader, Model &model, ModelSegment &segment);
    };

}
