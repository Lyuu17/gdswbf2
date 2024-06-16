
#pragma once

#include "Element.hpp"

namespace SWBF2::Native
{
    class Instance : public Element {
    public:
        std::string m_type;
        std::string m_name;

        godot::Basis m_rotationMatrix;
        godot::Vector3 m_position;
    };
}
