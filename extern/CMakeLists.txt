
# godot-cpp
set( GODOT_CPP_SYSTEM_HEADERS ON CACHE BOOL "" FORCE )

add_subdirectory(godot-cpp)

set_target_properties(godot-cpp
    PROPERTIES
        CXX_VISIBILITY_PRESET hidden    # visibility needs to be the same as the main library
)

# lua
add_subdirectory(lua)

target_compile_definitions(lua
    PUBLIC
        TRUST_BINARIES
        LUA_NUMBER=float
)
