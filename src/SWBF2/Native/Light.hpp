
#pragma once

#include "Models/Model.hpp"
#include "Texture/Texture.hpp"

#include "World.hpp"

namespace SWBF2::Native
{
    class Light {
    public:
        std::string m_name;
        godot::Vector3 m_position;
        godot::Quaternion m_rotation;
        uint32_t m_type;
        godot::Color m_color;
        bool m_castShadow;
        bool m_static;
        bool m_castSpecular;
        float m_range;
    };
}
