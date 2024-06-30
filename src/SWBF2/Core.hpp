#pragma once

#include <godot_cpp/classes/node.hpp>

namespace SWBF2
{
    class Core : public godot::Node {
        GDCLASS(Core, godot::Node)

    private:
        godot::String m_curMapName;

    public:
        Core();
        ~Core() = default;

    public:
        const godot::String &GetMapName() { return m_curMapName; };
        void LoadLevel(const godot::String &mapName);

    public:
        void _ready() override;

    private:
        static void _bind_methods();
    };
}
