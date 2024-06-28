
#pragma once

#include <godot_cpp/classes/mesh.hpp>

#include "Types.hpp"

#include "ModelSegment.hpp"

namespace SWBF2::Native
{
    typedef struct _MODEL_INFO
    {
        uint32_t m_unknown[4];
        godot::Vector3 m_vertexBox[2];
        godot::Vector3 m_visibilityBox[2];
        uint32_t m_faceCount;
    } ModelInfo;

    class Model {
    public:
        Model();
        ~Model() = default;

        std::string m_name;
        std::string m_node;
        ModelInfo m_info;
        std::vector<ModelSegment> m_segments;
    };
}
