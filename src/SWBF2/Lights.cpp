
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/directional_light3d.hpp>

#include "GameData.hpp"
#include "Level.hpp"

#include "Lights.hpp"

namespace SWBF2
{
    void Lights::_ready()
    {
        set_name("Lights");

        for (const auto &[id, light] : GameData::Instance()->GetMapData().m_lights)
        {
            godot::DirectionalLight3D *directionalLight3D = memnew(godot::DirectionalLight3D);
            directionalLight3D->set_name(light.m_name.c_str());
            directionalLight3D->set_position(light.m_position);
            directionalLight3D->set_rotation(light.m_rotation.get_euler());
            directionalLight3D->set_color(light.m_color);
            directionalLight3D->set_shadow(light.m_castShadow);
            directionalLight3D->set_param(godot::Light3D::PARAM_SPECULAR, light.m_castSpecular);
            directionalLight3D->set_param(godot::Light3D::PARAM_RANGE, light.m_range);

            add_child(directionalLight3D);

            directionalLight3D->set_owner(get_parent()->get_parent());
        }
    }

    void Lights::_process(double delta_time)
    {
    }

    void Lights::activate(bool active)
    {
    }

    bool Lights::active() const
    {
        return true;
    }

    void Lights::_bind_methods()
    {
    }
}
