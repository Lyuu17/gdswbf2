
#pragma once

#include <godot_cpp/classes/standard_material3d.hpp>
#include <godot_cpp/classes/texture2d.hpp>

#include "Pools.hpp"

namespace SWBF2
{
    class MaterialPools : public Pools<std::string, godot::StandardMaterial3D> {
    private:
        godot::Ref<godot::Texture> m_empty;

        const godot::Ref<godot::Texture> &findTexture(const std::string &id);
    public:

        godot::Ref<godot::StandardMaterial3D> &getItem(const std::string &key) override;
    };
}
