
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
}
