
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>

#include "Core.hpp"
#include "Level.hpp"

#include "SkyDome.hpp"

namespace SWBF2
{
    void SkyDome::_ready()
    {
        set_name("SkyDome");

        Level *level = godot::Object::cast_to<Level>(get_parent());

        for (const auto &domeModel : Core::Instance()->m_skyDome.m_domeModels)
        {
            godot::MeshInstance3D *mesh = level->LoadModel(domeModel.m_geometry);
            if (!mesh)
            {
                godot::UtilityFunctions::printerr(__FILE__, ":", __LINE__, ": Missing mesh for dome model ", domeModel.m_geometry.c_str());
                continue;
            }

            mesh->set_name(domeModel.m_geometry.c_str());
            mesh->set_scale({ 1000, 1000, 1000 });

            add_child(mesh);

            mesh->set_owner(this->get_parent());
        }
    }

    void SkyDome::_process(double delta_time)
    {
    }

    void SkyDome::activate(bool active)
    {
    }

    bool SkyDome::active() const
    {
        return true;
    }

    void SkyDome::_bind_methods()
    {
    }
}
