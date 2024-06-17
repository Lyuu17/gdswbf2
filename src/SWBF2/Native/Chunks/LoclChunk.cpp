
#include <godot_cpp/variant/utility_functions.hpp>

#include "Native/Chunks/StreamReader.hpp"
#include "Native/Chunks/ChunkProcessor.hpp"
#include "Native/Chunks/LoclChunk.hpp"
#include "Native/SWBF2.hpp"

namespace SWBF2::Native
{
    void LoclChunk::ProcessChunk(StreamReader &streamReader)
    {
        auto loclNameReaderChild = streamReader.ReadChildWithHeader<"NAME"_m>();

        std::string loclName;
        *loclNameReaderChild >> loclName;

        auto loclBodyReaderChild = streamReader.ReadChildWithHeader<"BODY"_m>();
        while (loclBodyReaderChild->RemainingBytes() > (sizeof(FNVHash) + sizeof(uint16_t)))
            ReadLoclEntries(*loclBodyReaderChild, loclName);
    }

    void LoclChunk::ReadLoclEntries(StreamReader &streamReader, const std::string &loclName)
    {
        FNVHash hash;
        streamReader >> hash;

        uint16_t size;
        streamReader >> size;

        if (size == 0)
            return;

        std::vector<char16_t> chars;
        chars.resize((size - sizeof(FNVHash) - sizeof(uint16_t)) / 2);

        streamReader >> chars;

        SWBF2::m_locl[loclName].insert_or_assign(hash, chars.data());
    }
}
