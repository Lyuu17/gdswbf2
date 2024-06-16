
#pragma once

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/standard_material3d.hpp>

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

        void LoadLevelMeshes();
        void LoadLevelInstances();

        void _process(double delta_time) override;

        void activate(bool active = true);
        bool active() const;

    protected:
        static void _bind_methods();
    };
}
