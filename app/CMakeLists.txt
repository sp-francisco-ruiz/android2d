cmake_minimum_required(VERSION 3.4.1)

project( android2d )

file(GLOB engine_actions_cpp "src/main/cpp/engine/actions/*.cpp")
file(GLOB engine_graphics_cpp "src/main/cpp/engine/graphics/*.cpp")
file(GLOB engine_platform_cpp "src/main/cpp/engine/platform/*.cpp")
file(GLOB engine_utils_cpp "src/main/cpp/engine/utils/*.cpp")
file(GLOB engine_physics_cpp "src/main/cpp/engine/physics/*.cpp")
file(GLOB game_cpp "src/main/cpp/game/*.cpp")

include_directories(src/main/cpp/)

add_library( native-lib
             SHARED
             ${game_cpp}
             ${engine_actions_cpp}
             ${engine_graphics_cpp}
             ${engine_physics_cpp}
             ${engine_platform_cpp}
             ${engine_utils_cpp})

find_library( log-lib log )
find_library( android-lib android )
find_library( egl-lib EGL )
find_library( gles-lib GLESv2 )

target_link_libraries( native-lib
                       ${log-lib}
                       ${android-lib}
                       ${egl-lib}
                       ${gles-lib})

#android_ndk_gdb_enable()

#target_link_libraries(native-lib log android)

#android_ndk_gdb_debuggable(native-lib)