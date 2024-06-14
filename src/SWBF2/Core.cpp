
#include <godot_cpp/variant/utility_functions.hpp>

#include "Core.hpp"
#include "Level.hpp"
#include "Version.h"

#include "Native/Chunks/ChunkProcessor.hpp"

#include <chrono>
#include <iostream>
#include <thread>

namespace SWBF2
{
    Core::Core()
    {
    }

    void Core::_ready()
    {
        set_name("Core");

        godot::UtilityFunctions::print("hello world!");

        // SWBF2::Native::UcfbChunk::ReadUcfbFile("data/_lvl_pc/common.lvl");
        // SWBF2::Native::UcfbChunk::ReadUcfbFile("data/_lvl_pc/core.lvl");

        Level *lvl = memnew(Level);
        add_child(lvl);
        lvl->set_owner(this);
    }

    void Core::_bind_methods()
    {
    }
}
