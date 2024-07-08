# SPDX-License-Identifier: Unlicense

target_sources(${PROJECT_NAME}
    PRIVATE
        "SWBF2/Native/Chunks/ChunkHeader.cpp"
        "SWBF2/Native/Chunks/ChunkProcessor.cpp"
        "SWBF2/Native/Chunks/ConfigReader.cpp"
        "SWBF2/Native/Chunks/LevelChunk.cpp"
        "SWBF2/Native/Chunks/LightChunk.cpp"
        "SWBF2/Native/Chunks/LoclChunk.cpp"
        "SWBF2/Native/Chunks/ModelChunk.cpp"
        "SWBF2/Native/Chunks/ObjectDefinitionChunk.cpp"
        "SWBF2/Native/Chunks/SkyChunk.cpp"
        "SWBF2/Native/Chunks/StreamReader.cpp"
        "SWBF2/Native/Chunks/TerrainChunk.cpp"
        "SWBF2/Native/Chunks/TextureChunk.cpp"
        "SWBF2/Native/Chunks/UcfbChunk.cpp"
        "SWBF2/Native/Chunks/WorldChunk.cpp"
        "SWBF2/Native/Models/Model.cpp"
        "SWBF2/Native/Scripting/Lua/LuaCallbacks.cpp"
        "SWBF2/Native/Scripting/Lua/ScriptCB.cpp"
        "SWBF2/Native/Texture/Texture.cpp"
        "SWBF2/Native/Texture/TextureUtils.cpp"
        "SWBF2/Native/Hashes.cpp"
        "SWBF2/Native/Level.cpp"
        "SWBF2/Native/Terrain.cpp"
        "SWBF2/Native/World.cpp"
        "SWBF2/Core.cpp"
        "SWBF2/Level.cpp"
        "SWBF2/Terrain.cpp"
        "SWBF2/MaterialPools.cpp"

        "RegisterExtension.cpp"
)

target_include_directories(${PROJECT_NAME} PRIVATE SWBF2)
