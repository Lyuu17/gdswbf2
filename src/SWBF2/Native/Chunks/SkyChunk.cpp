#include <godot_cpp/variant/utility_functions.hpp>

#include "Native/Chunks/ConfigReader.hpp"
#include "Native/Chunks/StreamReader.hpp"
#include "Native/Chunks/SkyChunk.hpp"

#include "Core.hpp"

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
                        Core::Instance()->m_skyDome.m_texture = val->m_string;
                        break;
                    }

                    case "DomeModel"_fnv:
                    {
                        ProcessDomeModels(val);
                        break;
                    }
                }
            }
        }
    }

    void SkyChunk::ProcessDomeModels(const std::unique_ptr<ConfigNode> &node)
    {
        for (const auto &[attr, val] : node->getNodes())
        {
            switch (attr)
            {
                case "Geometry"_fnv:
                {
                    Core::Instance()->m_skyDome.m_domeModels.push_back({ val->m_string });
                    break;
                }
            }
        }
    }
}
