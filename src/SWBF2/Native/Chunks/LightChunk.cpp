#include <godot_cpp/variant/utility_functions.hpp>

#include "Native/Chunks/ConfigReader.hpp"
#include "Native/Chunks/StreamReader.hpp"
#include "Native/Chunks/LightChunk.hpp"
#include "Native/SWBF2.hpp"

namespace SWBF2::Native
{
    void LightChunk::ProcessChunk(StreamReader &streamReader)
    {
        ConfigReader configReader{ streamReader };

        for (auto const &[id, node] : configReader.m_data.getNodes())
        {
            Light light{};
            light.m_name = node->m_string;

            for (auto const &[attr, val] : node->getNodes())
            {
                switch (attr)
                {
                    case "Position"_fnv:
                    {
                        light.m_position = val->ToVector3();
                        break;
                    }

                    case "Rotation"_fnv:
                    {
                        light.m_rotation = val->ToQuaternion();
                        break;
                    }

                    case "Color"_fnv:
                    {
                        light.m_color = val->ToColor();
                        break;
                    }

                    case 0xe7e90aee: // CastShadow
                    {
                        light.m_castShadow = true;
                        break;
                    }

                    case 0x489162bb: // Specular
                    {
                        light.m_castSpecular = (bool)val->m_float;
                        break;
                    }

                    case 0xd290c23b: // Static
                    {
                        light.m_static = true;
                        break;
                    }

                    case 0x84e26526: // PS2BlendMode
                    case 0xbfe60da6: // TileUV
                    case 0x6ac627c1: // OffsetUV
                        break;
                }
            }

            SWBF2::m_lights.emplace(light.m_name, light);
        }
    }
}
