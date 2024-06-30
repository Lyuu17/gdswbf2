
#pragma once

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/standard_material3d.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>

#include "MaterialPools.hpp"

namespace SWBF2
{
    class Level : public godot::Node3D {
        GDCLASS(Level, godot::Node3D)

    private:
        godot::String m_curMapName;
        godot::String m_curGamemode;

    public:
        Level() {}
        ~Level() = default;

        MaterialPools m_materialPool;

        godot::MeshInstance3D *LoadModel(const std::string &id);

    private:
        void LoadLevelInstances();
        void LoadWorldEnvironment();
        void LoadLights();

    public:
        const godot::String &GetMapName() { return m_curMapName; };
        void LoadLevel(const godot::String &mapName);

        const godot::String &GetGamemode() { return m_curGamemode; };
        void LoadGamemode(const godot::String &gamemode);
    public:
        virtual void _ready() override;

        void _process(double delta_time) override;

        void activate(bool active = true);
        bool active() const;

    protected:
        static void _bind_methods();
    };
}
