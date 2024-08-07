#pragma once

#include <godot_cpp/variant/utility_functions.hpp>

#include "Types.hpp"
#include "ChunkHeader.hpp"

namespace SWBF2::Native
{
    class StreamReader {

        ChunkHeader m_header;

        const std::byte *m_data;
        std::size_t m_head;

    public:
        StreamReader();
        StreamReader(const ChunkHeader &header, const std::byte *bytes);
        StreamReader(const std::vector<std::byte> &bytes);

        std::optional<StreamReader> ReadChild();

        template <uint32_t T>
        std::optional<StreamReader> ReadChildWithHeader()
        {
            auto reader = ReadChild();
            if (!reader)
                return std::nullopt;

            if (reader->GetHeader().m_Magic != T)
                return std::nullopt;

            return reader;
        }

        template <uint32_t header>
        bool IsNextHeader()
        {
            std::size_t prevhead = m_head;

            auto reader = ReadChild();

            m_head = prevhead;
            if (!reader)
                return false;

            if (reader->GetHeader().m_Magic != header)
                return false;

            return true;
        }

        template <uint32_t header1, uint32_t header2>
        bool IsNextHeader2()
        {
            std::size_t prevhead = m_head;

            auto reader1 = ReadChild();
            if (!reader1 || reader1->GetHeader().m_Magic != header1)
            {
                m_head = prevhead;
                return false;
            }

            auto reader2 = ReadChild();
            if (!reader2 || reader2->GetHeader().m_Magic != header2)
            {
                m_head = prevhead;
                return false;
            }

            m_head = prevhead;

            return true;
        }

        bool SkipBytes(uint32_t bytes);
        const ChunkHeader &GetHeader() const;
        std::size_t GetHead();
        std::size_t RemainingBytes();
        bool IsEof();
        void AlignHead();

        template<typename T>
        StreamReader &operator>>(T &value)
        {
            if (IsEof() || (m_head + sizeof(T)) > m_header.size) {
                throw std::runtime_error("eof");
            }

            std::memcpy(&value, &m_data[m_head], sizeof(T));

            m_head += sizeof(T);

            return *this;
        }

        template<typename T, std::size_t size>
        StreamReader &operator>>(T(&value)[size])
        {
            std::size_t totalSize = size * sizeof(T);

            if (IsEof() || (m_head + totalSize) > m_header.size) {
                throw std::runtime_error("eof");
            }

            std::memcpy(&value[0], &m_data[m_head], totalSize);

            m_head += totalSize;

            return *this;
        }

        template<typename T>
        StreamReader &operator>>(std::vector<T> &value)
        {
            std::size_t vecSize = value.size();
            std::size_t totalSize = vecSize * sizeof(T);

            if (IsEof() || (m_head + totalSize) > m_header.size) {
                throw std::runtime_error("eof");
            }

            std::memcpy(&value[0], &m_data[m_head], totalSize);

            m_head += totalSize;

            return *this;
        }

        StreamReader &operator>>(std::string &value)
        {
            const char *str = reinterpret_cast<const char *>(&m_data[m_head]);
            std::size_t len = std::distance(str, std::find(str, str + GetHeader().size, '\0'));

            value = std::string_view(str, len);

            m_head += len + 1;

            return *this;
        }

        StreamReader &operator>>(std::u8string &value)
        {
            const char8_t *str = reinterpret_cast<const char8_t *>(&m_data[m_head]);
            std::size_t len = std::distance(str, std::find(str, str + GetHeader().size, '\0'));

            value = std::u8string_view(str, len);

            return *this;
        }
    };
}
