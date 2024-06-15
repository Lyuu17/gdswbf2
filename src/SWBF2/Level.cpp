
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

        LoadLevelMeshes();
    }

    void Level::LoadLevelMeshes()
    {
        for (auto const &[id, model] : Native::Level::m_models)
        {
            uint32_t segment_id = 0;
            for (auto const &segment : model.m_segments)
            {
                godot::MeshInstance3D *meshInstance = memnew(godot::MeshInstance3D);
                meshInstance->set_name(std::format("{}_segm_{}", id, segment_id).c_str());

                godot::PackedVector3Array vertices;
                vertices.resize(segment.m_verticesBuf.m_positions.size());
                std::copy(segment.m_verticesBuf.m_positions.begin(), segment.m_verticesBuf.m_positions.end(), reinterpret_cast<Vector3<float>*>(vertices.ptrw()));

                godot::PackedVector3Array normals;
                normals.resize(segment.m_verticesBuf.m_normals.size());
                std::copy(segment.m_verticesBuf.m_normals.begin(), segment.m_verticesBuf.m_normals.end(), reinterpret_cast<Vector3<float>*>(normals.ptrw()));

                godot::PackedColorArray colors;
                colors.resize(segment.m_verticesBuf.m_colors.size());
                std::copy(segment.m_verticesBuf.m_colors.begin(), segment.m_verticesBuf.m_colors.end(), colors.ptrw());

                godot::PackedVector2Array uvs;
                uvs.resize(segment.m_verticesBuf.m_texCoords.size());
                std::copy(segment.m_verticesBuf.m_texCoords.begin(), segment.m_verticesBuf.m_texCoords.end(), reinterpret_cast<Vector2<float>*>(uvs.ptrw()));

                godot::PackedInt32Array indices;
                indices.resize(segment.m_indicesBuf.m_indices.size());
                std::copy(segment.m_indicesBuf.m_indices.begin(), segment.m_indicesBuf.m_indices.end(), indices.ptrw());

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

                if (!segment.m_textureNames.empty())
                {
                    static godot::Ref<godot::StandardMaterial3D> emptyGodotRef;

                    const auto &mainTextureName = segment.m_textureNames[Native::ModelSegment::TEXTURE_DEFAULT];
                    const auto &bumpTextureName = segment.m_textureNames[Native::ModelSegment::TEXTURE_NORMAL];

                    auto &material = m_materialPool.getItem(mainTextureName);
                    if (material.is_valid())
                    {
                        if (!bumpTextureName.empty() && Native::Level::m_tex.contains(bumpTextureName))
                        {
                            auto &bumpTexture = Native::Level::m_tex[bumpTextureName].m_formats[0].m_faceLevels[0].m_gdTexture;

                            material->set_feature(godot::BaseMaterial3D::FEATURE_NORMAL_MAPPING, true);
                            material->set_texture(godot::BaseMaterial3D::TEXTURE_NORMAL, bumpTexture);
                        }

                        if (segment.m_material.m_flags & Native::Material::MATERIAL_TRANSPARENT)
                            material->set_transparency(godot::BaseMaterial3D::TRANSPARENCY_ALPHA);

                        meshInstance->set_surface_override_material(0, material);
                    }
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
