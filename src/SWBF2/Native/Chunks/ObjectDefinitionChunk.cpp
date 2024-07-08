#include <godot_cpp/variant/utility_functions.hpp>

#include "Native/Chunks/ConfigReader.hpp"
#include "Native/Chunks/StreamReader.hpp"
#include "Native/Chunks/ObjectDefinitionChunk.hpp"
#include "Native/Objects/ObjectDefinition.hpp"

#include "Core.hpp"

namespace SWBF2::Native
{
    void ObjectDefinitionChunk::ProcessChunk(StreamReader &streamReader)
    {
        ObjectDefinition objDef{};

        auto baseReaderChild = streamReader.ReadChildWithHeader<"BASE"_m>();
        {
            *baseReaderChild >> objDef.m_classLabel;
        }

        std::string type;
        auto typeReaderChild = streamReader.ReadChildWithHeader<"TYPE"_m>();
        {
            *typeReaderChild >> type;
        }

        std::optional<StreamReader> propReaderChild;
        while ((propReaderChild = streamReader.ReadChildWithHeader<"PROP"_m>()).has_value())
        {
            FNVHash prop;
            *propReaderChild >> prop;

            std::string value;
            *propReaderChild >> value;

            objDef.m_properties.insert_or_assign(prop, value);
        }

        if (objDef.m_properties.contains("GeometryName"_fnv))
        {
            objDef.m_geometryName = objDef.m_properties["GeometryName"_fnv];
        }
        else // assumed geometry name by classLabel
        {
            if (objDef.m_classLabel == "grasspatch")
            {
                objDef.m_geometryName = "editor_grasspatch";
            }
        }

        Core::Instance()->m_objectDefs.insert_or_assign(type, objDef);
    }
}
