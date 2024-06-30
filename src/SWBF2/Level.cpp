
#include <godot_cpp/classes/class_db_singleton.hpp>
#include <godot_cpp/classes/array_mesh.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/image_texture.hpp>
#include <godot_cpp/classes/standard_material3d.hpp>
#include <godot_cpp/classes/environment.hpp>
#include <godot_cpp/classes/world_environment.hpp>
#include <godot_cpp/classes/sky.hpp>
#include <godot_cpp/classes/procedural_sky_material.hpp>
#include <godot_cpp/classes/directional_light3d.hpp>
#include <godot_cpp/variant/color.hpp>

#include "Native/Chunks/ChunkProcessor.hpp"
#include "Native/Models/ModelUtils.hpp"
#include "Native/Hashes.hpp"
#include "Native/SWBF2.hpp"

#include "Level.hpp"

namespace SWBF2
{
    void Level::_ready()
    {
        set_name("Level");
    }

    godot::MeshInstance3D *Level::LoadModel(const std::string &id)
    {
        if (!Native::SWBF2::m_models.contains(id) && !Native::SWBF2::m_objectDefs.contains(id))
        {
            return nullptr;
        }

        std::string newId = id;
        if (Native::SWBF2::m_objectDefs.contains(id))
        {
            newId = Native::SWBF2::m_objectDefs[id].m_geometryName;
            if (newId.empty())
                return nullptr;
        }

        const auto &model = Native::SWBF2::m_models[newId];

        godot::MeshInstance3D *meshInstance = memnew(godot::MeshInstance3D);
        meshInstance->set_name(newId.c_str());

        godot::ArrayMesh *arrMesh = memnew(godot::ArrayMesh);
        for (auto const &segment : model.m_segments)
        {
            godot::Array arrays;
            arrays.resize(godot::ArrayMesh::ARRAY_MAX);
            arrays[godot::ArrayMesh::ARRAY_VERTEX] = segment.m_verticesBuf.m_positions;
            arrays[godot::ArrayMesh::ARRAY_NORMAL] = segment.m_verticesBuf.m_normals;
            //arrays[godot::ArrayMesh::ARRAY_TANGENT] = tangents;
            if (segment.m_verticesBuf.m_colors.size() > 0)
                arrays[godot::ArrayMesh::ARRAY_COLOR] = segment.m_verticesBuf.m_colors;
            arrays[godot::ArrayMesh::ARRAY_TEX_UV] = segment.m_verticesBuf.m_texCoords;
            arrays[godot::ArrayMesh::ARRAY_INDEX] = segment.m_indicesBuf.m_indices;

            arrMesh->add_surface_from_arrays(Native::ModelUtils::DXtoGLPrimitiveType(segment.m_primitiveType), arrays);

            uint32_t surfaceId = arrMesh->get_surface_count() - 1;
            if (!segment.m_textureNames.empty())
            {
                const auto &mainTextureName = segment.m_textureNames[Native::ModelSegment::TEXTURE_DEFAULT];
                const auto &bumpTextureName = segment.m_textureNames[Native::ModelSegment::TEXTURE_NORMAL];

                if (!mainTextureName.empty())
                {
                    auto &material = m_materialPool.getItem(mainTextureName);
                    if (material.is_valid())
                    {
                        if (!bumpTextureName.empty() && Native::SWBF2::m_tex.contains(bumpTextureName))
                        {
                            auto &bumpTexture = Native::SWBF2::m_tex[bumpTextureName].m_formats[0].m_faceLevels[0].m_gdTexture;

                            material->set_feature(godot::BaseMaterial3D::FEATURE_NORMAL_MAPPING, true);
                            material->set_texture(godot::BaseMaterial3D::TEXTURE_NORMAL, bumpTexture);
                        }

                        // TODO: fix leaves transparency?
                        if (mainTextureName == "leaves")
                            material->set_transparency(godot::BaseMaterial3D::TRANSPARENCY_ALPHA_SCISSOR);

                        if (segment.m_material.m_flags & Native::Material::MATERIAL_TRANSPARENT)
                            material->set_transparency(godot::BaseMaterial3D::TRANSPARENCY_ALPHA);

                        arrMesh->surface_set_material(surfaceId, material);
                    }
                }
            }

            if (arrMesh->surface_get_material(surfaceId).is_null())
            {
                godot::UtilityFunctions::printerr(__FILE__, ":", __LINE__, ": Mesh ", id.c_str(), " has no texture at all");
            }
        }

        meshInstance->set_mesh(arrMesh);

        return meshInstance;
    }

    void Level::LoadLevelInstances()
    {
        for (const auto &[worldId, world] : Native::SWBF2::m_worlds)
        {
            for (const auto &inst : world.m_instances)
            {
                godot::MeshInstance3D *mesh = LoadModel(inst.m_type);
                if (!mesh)
                {
                    godot::UtilityFunctions::printerr(__FILE__, ":", __LINE__, ": Missing mesh for instance ", inst.m_type.c_str());
                    continue;
                }

                mesh->set_name(inst.m_name.c_str());
                mesh->translate(inst.m_position);
                mesh->set_basis(inst.m_rotationMatrix);

                add_child(mesh);

                mesh->set_owner(this->get_parent());
                mesh->set_unique_name_in_owner(true);
            }
        }
    }

    void Level::LoadWorldEnvironment()
    {
        godot::WorldEnvironment *worldEnv = memnew(godot::WorldEnvironment);
        {
            worldEnv->set_name("WorldEnvironment");

            godot::Environment *env = memnew(godot::Environment);
            {
                godot::Sky *sky = memnew(godot::Sky);
                {
                    const auto &textureName = Native::SWBF2::m_skyDome.m_texture;

                    if (Native::SWBF2::m_tex.contains(textureName))
                    {
                        auto &texture = Native::SWBF2::m_tex[textureName].m_formats[0].m_faceLevels[0].m_gdTexture;
                        godot::ProceduralSkyMaterial *procSkyMaterial = memnew(godot::ProceduralSkyMaterial);
                        procSkyMaterial->set_sky_cover(texture);

                        sky->set_material(procSkyMaterial);
                    }
                }

                env->set_background(godot::Environment::BG_SKY);
                env->set_sky(sky);
            }

            worldEnv->set_environment(env);
        }

        add_child(worldEnv);

        worldEnv->set_owner(this->get_parent());
    }

    void Level::LoadLights()
    {
        for (const auto &[id, light] : SWBF2::Native::SWBF2::m_lights)
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

            directionalLight3D->set_owner(get_parent());
        }
    }

    void Level::LoadLevel(const godot::String &mapName)
    {
        m_curMapName = mapName;

        if (!Native::SWBF2::LoadLevelFile(mapName.ascii().get_data()))
            throw std::runtime_error{ "failed to load the game level" };

        LoadLevelInstances();
        LoadWorldEnvironment();
        LoadLights();
    }

    void Level::LoadGamemode(const godot::String &gamemode)
    {
    }

    void Level::_process(double delta_time)
    {
    }

    void Level::activate(bool active)
    {
    }

    bool Level::active() const
    {
        return true;
    }

    void Level::_bind_methods()
    {
    }
}
