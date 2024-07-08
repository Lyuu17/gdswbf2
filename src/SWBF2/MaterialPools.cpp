
#include "GameData.hpp"

#include "MaterialPools.hpp"

namespace SWBF2
{
    const godot::Ref<godot::Texture> &SWBF2::MaterialPools::findTexture(const std::string &id)
    {
        const auto &mapData = GameData::Instance()->GetMapData();
        if (!mapData.m_tex.contains(id))
            return m_empty;

        auto &tex = mapData.m_tex.at(id);
        auto &gdTex = tex.m_formats.at(0).m_faceLevels.at(0).m_gdTexture;
        return gdTex;
    }

    godot::Ref<godot::StandardMaterial3D> &MaterialPools::getItem(const std::string &key)
    {
        auto &texture = findTexture(key);

        godot::Ref<godot::StandardMaterial3D> material = memnew(godot::StandardMaterial3D);
        material->set_texture(godot::StandardMaterial3D::TEXTURE_ALBEDO, texture);
        material->set_flag(godot::BaseMaterial3D::FLAG_ALBEDO_FROM_VERTEX_COLOR, true);
        material->set_cull_mode(godot::BaseMaterial3D::CULL_DISABLED);

        m_pool.emplace(key, material);

        return m_pool[key];
    }
}
