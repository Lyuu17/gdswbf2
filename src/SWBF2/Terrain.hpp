
#pragma once

#include <godot_cpp/classes/mesh_instance3d.hpp>

namespace SWBF2
{
    class Terrain : public godot::MeshInstance3D {
        GDCLASS(Terrain, godot::MeshInstance3D)

    public:
        Terrain() {}
        ~Terrain() = default;

    public:
        void LoadTerrain();

    public:
        virtual void _ready() override;

        void _process(double delta_time) override;

        void activate(bool active = true);
        bool active() const;

    protected:
        static void _bind_methods();
    };
}
