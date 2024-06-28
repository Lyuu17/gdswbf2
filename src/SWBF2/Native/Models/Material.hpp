
#pragma once

#include "Types.hpp"

namespace SWBF2::Native
{
    class Material {
    public:
        enum MaterialFlags : uint32_t {
            MATERIAL_NORMAL = 1,
            MATERIAL_HARDEDGED = 2,
            MATERIAL_TRANSPARENT = 4,
            MATERIAL_GLOSSMAP = 8,
            MATERIAL_GLOW = 16,
            MATERIAL_BUMPMAP = 32,
            MATERIAL_ADDITIVE = 64,
            MATERIAL_SPECULAR = 128,
            MATERIAL_ENVMAP = 256,
            MATERIAL_VERTEXLIGHTING = 512,
            MATERIAL_TILEDNORMALMAP = 2048,
            MATERIAL_DOUBLESIDED = 65536,

            MATERIAL_SCROLLING = 16777216,
            MATERIAL_ENERGY = 33554432,
            MATERIAL_ANIMATED = 67108864,

            MATERIAL_ATTACHEDLIGHT = 134217728,
        };

        MaterialFlags m_flags;
        godot::Color m_diffuseColor;
        godot::Color m_specularColor;
        uint32_t m_specularExponent;
        uint32_t m_parameters[2];
        std::string m_attachedLight;
    };
}
