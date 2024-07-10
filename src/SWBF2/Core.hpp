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
        godot::String m_language;
        godot::String m_platform;

    public: // variables
        Gamemode m_curGamemode;

    public: // methods
        Core();
        ~Core();

        static Core *Instance();

        const godot::String &GetMapName() { return m_curMapName; };
        void LoadLevel(const godot::String &mapName);

        const godot::String &GetLanguage() { return m_language; };
        void SetLanguage(const godot::String &language) { m_language = language; };

        const godot::String &GetPlatform() { return m_platform; };

        void _ready() override;

    private:
        static void _bind_methods();
    };
}
