
#include <godot_cpp/classes/array_mesh.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/image_texture.hpp>
#include <godot_cpp/classes/standard_material3d.hpp>
#include <godot_cpp/variant/color.hpp>

#include "Native/Chunks/ChunkProcessor.hpp"
#include "Native/Level.hpp"

#include "Level.hpp"

namespace SWBF2
{
    void Level::_ready()
    {
        set_name("Level");

        SWBF2::Native::UcfbChunk::ReadUcfbFile("data/_lvl_pc/cor/cor1.lvl");

        LoadMeshes();
    }

    void Level::LoadMeshes()
    {
        for (auto const &[id, model] : Native::Level::m_models)
        {
            uint32_t segment_id = 0;
            for (auto const &segment : model.m_segments)
            {
                godot::MeshInstance3D *meshInstance = memnew(godot::MeshInstance3D);
                meshInstance->set_name(std::format("{}_segm_{}", id, segment_id).c_str());

                godot::PackedVector3Array vertices;
                godot::PackedVector3Array normals;
                //godot::PackedVector3Array tangents;
                godot::PackedColorArray colors;
                godot::PackedVector2Array uvs;
                godot::PackedInt32Array indices;

                for (const auto &position : segment.m_verticesBuf.m_positions)
                {
                    vertices.push_back({ position.x, position.y, position.z });
                }

                for (const auto &normal : segment.m_verticesBuf.m_normals)
                {
                    normals.push_back({ normal.x, normal.y, normal.z });
                }

                /*for (uint32_t i = 0; i < segment.m_verticesBuf.m_tangents.size(); i++)
                {
                    tangents.push_back({ segment.m_verticesBuf.m_tangents[i].x, segment.m_verticesBuf.m_tangents[i].y, segment.m_verticesBuf.m_tangents[i].z });
                }*/

                for (const auto &color : segment.m_verticesBuf.m_colors)
                {
                    colors.push_back({ (float)color.color.r / 255.0f, (float)color.color.g / 255.0f, (float)color.color.b / 255.0f, (float)color.color.a / 255.0f });
                }

                for (const auto &texCoord : segment.m_verticesBuf.m_texCoords)
                {
                    uvs.push_back({ texCoord.x, texCoord.y });
                }

                for (std::size_t i = 0; i < segment.m_indicesBuf.m_indices.size(); i++)
                {
                    indices.push_back({ segment.m_indicesBuf.m_indices[i] });
                }

                godot::Array arrays;
                arrays.resize(godot::ArrayMesh::ARRAY_MAX);
                arrays[godot::ArrayMesh::ARRAY_VERTEX] = vertices;
                arrays[godot::ArrayMesh::ARRAY_NORMAL] = normals;
                //arrays[godot::ArrayMesh::ARRAY_TANGENT] = tangents;
                arrays[godot::ArrayMesh::ARRAY_COLOR] = colors;
                arrays[godot::ArrayMesh::ARRAY_TEX_UV] = uvs;
                arrays[godot::ArrayMesh::ARRAY_INDEX] = indices;

                godot::ArrayMesh *arrMesh = memnew(godot::ArrayMesh);
                arrMesh->add_surface_from_arrays(godot::Mesh::PRIMITIVE_TRIANGLE_STRIP, arrays);

                meshInstance->set_mesh(arrMesh);

                auto tex_id = 0;
                for (const auto &texName : segment.m_textureNames)
                {
                    // TODO, apply bump to texture
                    if (texName.ends_with("bump"))
                        continue;

                    auto &material = m_materialPool.getItem(texName);
                    if (material.is_null())
                    {
                        godot::UtilityFunctions::printerr(__FILE__, ":", __LINE__, ": No material found for ", texName.c_str());
                        continue;
                    }

                    godot::UtilityFunctions::print(__FILE__, ":", __LINE__, ": Found texture ", texName.c_str(), " for mesh ", id.c_str(), " with segment id ", segment_id);

                    // if (segment.m_material.m_flags & Native::MaterialFlags::Transparent)
                    //    material->set_transparency(godot::BaseMaterial3D::TRANSPARENCY_ALPHA_SCISSOR);

                    meshInstance->set_surface_override_material(0, material);

                    tex_id++;
                }

                if (meshInstance->get_material_override().is_null())
                {
                    godot::UtilityFunctions::printerr(__FILE__, ":", __LINE__, ": Mesh ", id.c_str(), " has no texture at all");
                }

                add_child(meshInstance);
                meshInstance->set_owner(this->get_parent());
                meshInstance->add_to_group("Level Meshes");

                segment_id++;
            }
        }
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
