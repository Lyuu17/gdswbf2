
#include <godot_cpp/classes/class_db_singleton.hpp>
#include <godot_cpp/classes/array_mesh.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/image_texture.hpp>
#include <godot_cpp/classes/standard_material3d.hpp>
#include <godot_cpp/classes/environment.hpp>
#include <godot_cpp/classes/world_environment.hpp>
#include <godot_cpp/classes/sky.hpp>
#include <godot_cpp/classes/procedural_sky_material.hpp>
#include <godot_cpp/classes/panorama_sky_material.hpp>
#include <godot_cpp/variant/color.hpp>

#include "Native/Chunks/ChunkProcessor.hpp"
#include "Native/Models/ModelUtils.hpp"
#include "Native/Hashes.hpp"

#include "Core.hpp"
#include "Terrain.hpp"
#include "SkyDome.hpp"
#include "Lights.hpp"
#include "WorldObjects.hpp"

#include "Level.hpp"

namespace SWBF2
{
    Level::Level()
    {
    }

    Level::~Level()
    {
    }

    void Level::_ready()
    {
        set_name("Level");

        Terrain *terr = memnew(Terrain);
        add_child(terr);
        terr->set_owner(get_parent());

        SkyDome *skyDome = memnew(SkyDome);
        add_child(skyDome);
        skyDome->set_owner(get_parent());

        Lights *lights = memnew(Lights);
        add_child(lights);
        lights->set_owner(get_parent());

        WorldObjects *objs = memnew(WorldObjects);
        add_child(objs);
        objs->set_owner(get_parent());
    }

    godot::MeshInstance3D *Level::LoadModel(const std::string &id)
    {
        if (!Core::Instance()->m_models.contains(id) && !Core::Instance()->m_objectDefs.contains(id))
        {
            return nullptr;
        }

        std::string newId = id;
        if (Core::Instance() ->m_objectDefs.contains(id))
        {
            newId = Core::Instance()->m_objectDefs[id].m_geometryName;
            if (newId.empty())
                return nullptr;
        }

        const auto &model = Core::Instance()->m_models[newId];

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
                        if (!bumpTextureName.empty() && Core::Instance()->m_tex.contains(bumpTextureName))
                        {
                            auto &bumpTexture = Core::Instance()->m_tex[bumpTextureName].m_formats[0].m_faceLevels[0].m_gdTexture;

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

    void Level::LoadWorldEnvironment()
    {
        godot::WorldEnvironment *worldEnv = memnew(godot::WorldEnvironment);
        {
            worldEnv->set_name("WorldEnvironment");

            godot::Environment *env = memnew(godot::Environment);
            {
                godot::Sky *sky = memnew(godot::Sky);
                {
                    const auto &textureName = Core::Instance()->m_skyDome.m_texture;
                    if (Core::Instance()->m_tex.contains(textureName))
                    {
                        godot::PanoramaSkyMaterial *panoramaSkyMat = memnew(godot::PanoramaSkyMaterial);

                        auto &texture = Core::Instance()->m_tex[textureName].m_formats[0].m_faceLevels[0].m_gdTexture;
                        panoramaSkyMat->set_panorama(texture);

                        sky->set_material(panoramaSkyMat);
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

    void Level::LoadLevel(const godot::String &mapName)
    {
        m_curMapName = mapName;

        LoadWorldEnvironment();
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
