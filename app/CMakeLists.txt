cmake_minimum_required( VERSION 3.4.1 )

project( android2d )

file( GLOB platform_cpp "src/main/cpp/platform/*.cpp" )
file( GLOB engine_cpp "src/main/cpp/engine/*.cpp" )
file( GLOB utils_cpp "src/main/cpp/utils/*.cpp" )
file( GLOB game_cpp "src/main/cpp/game/*.cpp" )

include_directories(src/main/cpp/)

add_library( native-lib
             SHARED
             ${platform_cpp}
             ${engine_cpp}
             ${utils_cpp}
             ${game_cpp} )

find_library( log-lib log )
find_library( android-lib android )
find_library( egl-lib EGL )
find_library( gles-lib GLESv2 )

target_link_libraries( native-lib
                       ${log-lib}
                       ${android-lib}
                       ${egl-lib}
                       ${gles-lib} )