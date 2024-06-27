#include <godot_cpp/variant/utility_functions.hpp>

#include "Native/Chunks/ConfigReader.hpp"
#include "Native/Chunks/StreamReader.hpp"
#include "Native/Chunks/SkyChunk.hpp"
#include "Native/SWBF2.hpp"

namespace SWBF2::Native
{
    void SkyChunk::ProcessChunk(StreamReader &streamReader)
    {
        ConfigReader configReader{ streamReader };

        for (auto const &[idhead, headnode] : configReader.m_data.getNodes())
        {
            for (auto const &[attr, val] : headnode->getNodes())
            {
                switch (attr)
                {
                    case "Texture"_fnv:
                    {
                        SWBF2::m_skyDome.m_texture = val->m_string;
                        break;
                    }
                }
            }
        }
    }
}
