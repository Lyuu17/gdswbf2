
#pragma once

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/standard_material3d.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>

#include "MaterialPools.hpp"

namespace SWBF2
{
    class Level : public godot::Node3D {
        GDCLASS(Level, godot::Node3D)

    public:
        Level() {}
        ~Level() = default;

        MaterialPools m_materialPool;

        virtual void _ready() override;

        godot::MeshInstance3D *LoadModel(const std::string &id);
        void LoadLevelInstances();
        void LoadWorldEnvironment();
        void LoadLights();

        void _process(double delta_time) override;

        void activate(bool active = true);
        bool active() const;

    protected:
        static void _bind_methods();
    };
}
