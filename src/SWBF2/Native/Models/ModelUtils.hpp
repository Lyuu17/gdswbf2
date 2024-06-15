
#pragma once

#include <godot_cpp/classes/mesh.hpp>

#include "ModelSegment.hpp"

namespace SWBF2::Native::ModelUtils
{
    inline static godot::Mesh::PrimitiveType DXtoGLPrimitiveType(PrimitiveType primitiveType)
    {
        switch (primitiveType)
        {
            case PrimitiveType::POINTLIST:
                return godot::Mesh::PRIMITIVE_POINTS;
            case PrimitiveType::LINELIST:
                return godot::Mesh::PRIMITIVE_LINES;
            case PrimitiveType::LINESTRIP:
                return godot::Mesh::PRIMITIVE_LINE_STRIP;
            case PrimitiveType::TRIANGLELIST:
                return godot::Mesh::PRIMITIVE_TRIANGLES;
            case PrimitiveType::TRIANGLESTRIP:
                return godot::Mesh::PRIMITIVE_TRIANGLE_STRIP;
            case PrimitiveType::TRIANGLEFAN:
            default:
                throw std::runtime_error{ "invalid primitiveType" };
        }
    }
}
