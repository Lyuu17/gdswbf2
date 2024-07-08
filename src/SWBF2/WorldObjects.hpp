
#pragma once

#include <godot_cpp/classes/node.hpp>

namespace SWBF2
{
    class WorldObjects : public godot::Node {
        GDCLASS(WorldObjects, godot::Node)

    public:
        virtual void _ready() override;

        void _process(double delta_time) override;

        void activate(bool active = true);
        bool active() const;

    protected:
        static void _bind_methods();
    };
}
