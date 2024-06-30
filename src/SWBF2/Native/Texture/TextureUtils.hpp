
#pragma once

#include <godot_cpp/classes/image.hpp>

#include "Native/D3D9/d3dformat.hpp"

namespace SWBF2::Native::TextureUtils
{
    inline godot::Image::Format D3DToGLFormat(D3DFORMAT format)
    {
        switch (format)
        {
            case D3DFMT_DXT1:
                return godot::Image::FORMAT_DXT1;
            case D3DFMT_DXT3:
                return godot::Image::FORMAT_DXT3;
            case D3DFMT_R5G6B5:
                return godot::Image::FORMAT_RGB565;
            case D3DFMT_L8:
                return godot::Image::FORMAT_L8;
            default:
                throw std::runtime_error{ "unsupported image format" };
        }
    }

    inline bool IsD3DFormatSupported(D3DFORMAT format)
    {
        switch (format)
        {
            case D3DFMT_DXT1:
            case D3DFMT_DXT3:
            case D3DFMT_R5G6B5:
            case D3DFMT_L8:
                return true;
            default:
                return false;
        }
    }

    inline uint32_t ConvertD3DFMT_A4R4G4B4ToRGBA(uint16_t d3dPixel) {
        uint8_t alpha = (d3dPixel >> 12) & 0xF;
        uint8_t red = (d3dPixel >> 8) & 0xF;
        uint8_t green = (d3dPixel >> 4) & 0xF;
        uint8_t blue = d3dPixel & 0xF;

        // Scale components from 4 bits to 8 bits
        alpha *= 16;
        red *= 16;
        green *= 16;
        blue *= 16;

        // Construct the RGBA value
        return (alpha << 24) | (red << 16) | (green << 8) | blue;
    }

    inline std::pair<godot::Image::Format, godot::PackedByteArray> godotTextureConvert(uint32_t width, uint32_t height, D3DFORMAT fmt, std::vector<std::byte> bytes)
    {
        godot::PackedByteArray imageBuf{};
        if (TextureUtils::IsD3DFormatSupported(fmt))
        {
            imageBuf.resize(bytes.size());
            std::copy(bytes.begin(), bytes.end(), (std::byte *)imageBuf.ptrw());
            return { D3DToGLFormat(fmt), imageBuf };
        }

        imageBuf.resize(width * height * 2);

        for (uint32_t y = 0; y < height; ++y) {
            for (uint32_t x = 0; x < width; ++x) {
                uint16_t d3dPixel = reinterpret_cast<uint16_t &>(bytes[y * width + x]);
                (uint32_t &)imageBuf[y * width + x] = ConvertD3DFMT_A4R4G4B4ToRGBA(d3dPixel);
            }
        }

        return { godot::Image::FORMAT_RGBA4444, imageBuf };
    }
}
