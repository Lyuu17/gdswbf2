#include <godot_cpp/variant/utility_functions.hpp>

#include "Native/Chunks/StreamReader.hpp"
#include "Native/Chunks/TerrainChunk.hpp"
#include "Native/Terrain.hpp"

#include "GameData.hpp"

namespace SWBF2::Native
{
    enum class VBufType : uint32_t {
        GEOMETRY = 290,
        TEXTURE = 20770,
        TEXTURE_EXTRA = 130
    };

    void TerrainChunk::ProcessChunk(const std::string &filename, StreamReader &streamReader)
    {
        Terrain tern{};

        auto nameReaderChild = streamReader.ReadChildWithHeader<"NAME"_m>();
        {
            *nameReaderChild >> tern.m_name;
        }

        if (streamReader.IsEof())
            return; // No terrain

        auto infoReaderChild = streamReader.ReadChildWithHeader<"INFO"_m>();
        if (infoReaderChild)
        {
            *infoReaderChild >> tern.m_gridUnitSize;
            *infoReaderChild >> tern.m_heightScale;
            *infoReaderChild >> tern.m_heightFloor;
            *infoReaderChild >> tern.m_heightCeiling;
            *infoReaderChild >> tern.m_gridSize;
            *infoReaderChild >> tern.m_heightPatches;
            *infoReaderChild >> tern.m_texturePatches;
            *infoReaderChild >> tern.m_textureCount;
            *infoReaderChild >> tern.m_maxTextureLayers;
            *infoReaderChild >> tern.m_unknown;
        }

        auto ltexChild = streamReader.ReadChildWithHeader<"LTEX"_m>();
        if (ltexChild)
        {
            for (int i = 0; i < tern.m_textureCount; i++)
            {
                std::string texName;
                *ltexChild >> texName;

                tern.m_textures.push_back(texName);
            }
        }

        auto dtexReaderChild = streamReader.ReadChildWithHeader<"DTEX"_m>();
        if (dtexReaderChild)
        {
            // unused?
            dtexReaderChild->SkipBytes((uint32_t)dtexReaderChild->RemainingBytes());
        }

        auto dtlxReaderChild = streamReader.ReadChildWithHeader<"DTLX"_m>();
        if (dtlxReaderChild)
        {
            *dtlxReaderChild >> tern.m_detailTexture;
        }

        auto scalChild = streamReader.ReadChildWithHeader<"SCAL"_m>();
        if (scalChild)
        {
            for (int i = 0; i < tern.m_textureCount; i++)
            {
                float scal;
                *scalChild >> scal;

                tern.m_textureScales.push_back(scal);
            }
        }

        auto axisChild = streamReader.ReadChildWithHeader<"AXIS"_m>();
        if (axisChild)
        {
            for (int i = 0; i < tern.m_textureCount; i++)
            {
                uint8_t axis;
                *axisChild >> axis;

                tern.m_textureAxis.push_back(axis);
            }
        }

        auto rotnChild = streamReader.ReadChildWithHeader<"ROTN"_m>();
        if (rotnChild)
        {
            for (int i = 0; i < tern.m_textureCount; i++)
            {
                float rotn;
                *rotnChild >> rotn;

                tern.m_textureRotn.push_back(rotn);
            }
        }

        std::optional<StreamReader> readerChild;
        while ((readerChild = streamReader.ReadChild()).has_value())
        {
            switch (readerChild->GetHeader().m_Magic)
            {
                case "PCHS"_m:
                {
                    StreamReader r{ *readerChild };
                    ReadPatches(r, tern);
                    break;
                }
                case "WATR"_m:
                    // todo
                    break;
            }
        }

        GameData::Instance()->m_tern = tern;
    }

    void TerrainChunk::ReadPatches(StreamReader &streamReader, Terrain &tern)
    {
        auto comnReaderChild = streamReader.ReadChildWithHeader<"COMN"_m>();
        {
            // whats this
            comnReaderChild->SkipBytes((uint32_t)comnReaderChild->RemainingBytes());
        }

        std::optional<StreamReader> ptchReaderChild;
        while ((ptchReaderChild = streamReader.ReadChildWithHeader<"PTCH"_m>()).has_value())
        {
            StreamReader r{ *ptchReaderChild };
            ReadPatch(r, tern);
        }
    }

    void TerrainChunk::ReadPatch(StreamReader &streamReader, Terrain &tern)
    {
        TerrainPatch ptch;

        auto infoReaderChild = streamReader.ReadChildWithHeader<"INFO"_m>();
        {}

        std::optional<StreamReader> readerChild;
        while ((readerChild = streamReader.ReadChildWithHeader<"VBUF"_m>()).has_value())
        {
            uint32_t elementCount;
            *readerChild >> elementCount;

            uint32_t elementSize;
            *readerChild >> elementSize;

            VBufType elementType;
            *readerChild >> elementType;

            if (elementType == VBufType::TEXTURE_EXTRA)
            {
                std::vector<TerrainTextureVBufExtraEntry> vbuf;
                vbuf.resize(elementCount);

                *readerChild >> vbuf;

                ptch.m_vertices.m_texturesExtra = vbuf;

                if (streamReader.IsNextHeader<"IBUF"_m>())
                {
                    readerChild = streamReader.ReadChildWithHeader<"IBUF"_m>();
                    *readerChild >> elementCount;

                    ptch.m_indices.m_textureExtra.resize(elementCount);

                    *readerChild >> ptch.m_indices.m_textureExtra;
                }
            }
            else if (elementType == VBufType::TEXTURE)
            {
                std::vector<TerrainTextureVBufEntry> vbuf;
                vbuf.resize(elementCount);

                *readerChild >> vbuf;

                ptch.m_vertices.m_textures = vbuf;

                if (streamReader.IsNextHeader<"IBUF"_m>())
                {
                    throw std::runtime_error{ "not implemented" };
                }
            }
            else if (elementType == VBufType::GEOMETRY)
            {
                std::vector<TerrainGeometryVBufEntry> vbuf;
                vbuf.resize(elementCount);

                *readerChild >> vbuf;

                ptch.m_vertices.m_geometry = vbuf;

                if (streamReader.IsNextHeader<"IBUF"_m>())
                {
                    readerChild = streamReader.ReadChildWithHeader<"IBUF"_m>();
                    *readerChild >> elementCount;

                    ptch.m_indices.m_geometry.resize(elementCount);

                    *readerChild >> ptch.m_indices.m_geometry;
                }
            }
            else
            {
                throw std::runtime_error{ "Unknown VBUF type encountered in terrain." };
            }
        }

        tern.m_patches.push_back(ptch);
    }
}
