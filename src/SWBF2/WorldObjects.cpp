
#include <godot_cpp/variant/utility_functions.hpp>

#include "Level.hpp"
#include "GameData.hpp"

#include "WorldObjects.hpp"

namespace SWBF2
{
    void WorldObjects::_ready()
    {
        set_name("Objects");

        Level *level = godot::Object::cast_to<Level>(get_parent());

        for (const auto &[worldId, world] : GameData::Instance()->GetMapData().m_worlds)
        {
            for (const auto &inst : world.m_instances)
            {
                godot::MeshInstance3D *mesh = level->LoadModel(inst.m_type);
                if (!mesh)
                {
                    godot::UtilityFunctions::printerr(__FILE__, ":", __LINE__, ": Missing mesh for instance ", inst.m_type.c_str());
                    continue;
                }

                mesh->set_name(inst.m_name.c_str());
                mesh->translate(inst.m_position);
                mesh->set_basis(inst.m_rotationMatrix);

                add_child(mesh);

                mesh->set_owner(get_parent()->get_parent());
                mesh->set_unique_name_in_owner(true);
            }
        }
    }

    void WorldObjects::_process(double delta_time)
    {
    }

    void WorldObjects::activate(bool active)
    {
    }

    bool WorldObjects::active() const
    {
        return true;
    }

    void WorldObjects::_bind_methods()
    {
    }
}
