#pragma once

#include <godot_cpp/classes/node.hpp>

#include <lua.h>

#include "Native/Models/Model.hpp"
#include "Native/Texture/Texture.hpp"
#include "Native/Objects/ObjectDefinition.hpp"
#include "Native/Level.hpp"
#include "Native/SkyDome.hpp"
#include "Native/Light.hpp"
#include "Native/Terrain.hpp"

namespace SWBF2
{
    class Core : public godot::Node {
        GDCLASS(Core, godot::Node)

    private:
        static Core *m_instance;

        godot::String m_curMapName;
        godot::String m_platform;

    public: // variables
        Gamemode m_curGamemode;
        Language m_language;

    public: // methods
        Core();
        ~Core();

        static Core *Instance();

        const godot::String &GetMapName() { return m_curMapName; };
        void LoadLevel(const godot::String &mapName);

        const godot::String &GetLanguage() const {
            static godot::String str{ std::string{ DefaultLanguages.at(m_language) }.c_str() };
            return str;
        }

        void SetLanguage(const godot::String &language) { m_language = DefaultLanguagesByName.at(language.ascii().get_data()); }

        const godot::String &GetPlatform() { return m_platform; };

        void _ready() override;

    private:
        static void _bind_methods();
    };
}
