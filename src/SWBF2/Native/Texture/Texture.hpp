
#pragma once

#include <godot_cpp/classes/texture.hpp>

#include "Native/D3D9/d3dformat.hpp"

namespace SWBF2::Native
{
    typedef struct _TEX_FMT_FACE_LVL
    {
        uint32_t m_mipLevel;
        uint32_t m_bodySize;
        std::vector<std::byte> m_imageInBytes;

        godot::Ref<godot::Texture> m_gdTexture;
    } TextureFormatFaceLevel;

    typedef struct _TEX_FMT
    {
        D3DFORMAT m_format;
        uint16_t m_width;
        uint16_t m_height;
        uint16_t m_depth;
        uint16_t m_mipmapCount;
        uint32_t m_typeDetailBias;

        std::vector<TextureFormatFaceLevel> m_faceLevels;
    } TextureFormat;

    class Texture {
    public:
        std::string m_name;

        uint32_t m_formatCount;
        std::vector<D3DFORMAT> m_d3dFormats;

        std::vector<TextureFormat> m_formats;
    };
}
