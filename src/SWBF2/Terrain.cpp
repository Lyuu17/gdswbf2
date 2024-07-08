
#pragma once

#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/mesh_library.hpp>
#include <godot_cpp/classes/plane_mesh.hpp>
#include <godot_cpp/classes/triangle_mesh.hpp>
#include <godot_cpp/classes/array_mesh.hpp>
#include <godot_cpp/godot.hpp>

#include "Core.hpp"
#include "Terrain.hpp"
#include "Level.hpp"

namespace SWBF2
{
    void Terrain::_ready()
    {
        set_name("Terrain");
    }

    void Terrain::_process(double delta_time)
    {
    }

    void Terrain::activate(bool active)
    {
    }

    bool Terrain::active() const
    {
        return true;
    }

    void Terrain::_bind_methods()
    {
    }
}
