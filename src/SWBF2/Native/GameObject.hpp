
#pragma once

namespace SWBF2::Native
{
    class GameObject {
    public:
        std::string m_type;
        std::string m_name;

        godot::Basis m_rotationMatrix;
        godot::Vector3 m_position;

        std::unordered_map<uint32_t, std::string> m_properties;
    };
}
