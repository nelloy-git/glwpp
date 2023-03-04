cmake_minimum_required(VERSION 3.1...3.17 FATAL_ERROR)

project(glwpp VERSION 0.1 LANGUAGES C CXX)

add_subdirectory(./3rdparty/assimp)
add_subdirectory(./3rdparty/glfw)
add_subdirectory(./3rdparty/googletest)
add_subdirectory(./3rdparty/freetype)
add_subdirectory(./test)

add_compile_definitions(GLWPP_DEBUG)
add_compile_definitions(IMGUI_IMPL_OPENGL_DEBUG)
if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi /WX /D_DEBUG /DEBUG:FULL /std:c++latest")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23 -fconcepts -pthread -fmax-errors=1")
endif (WIN32)

include_directories(./src)
include_directories(./src/gl)
include_directories(./3rdparty/assimp/include)
include_directories(./3rdparty/glad/include)
include_directories(./3rdparty/glfw/include)
include_directories(./3rdparty/glm)
include_directories(./3rdparty/magic_enum/include)
include_directories(./3rdparty/thread_pool)
include_directories(./3rdparty/VLD/include)
link_directories(./3rdparty/VLD/lib/Win64)
include_directories(./3rdparty/freetype/include)
include_directories(3rdparty/imgui)
include_directories(3rdparty/imgui/backends)
include_directories(3rdparty/imgui-filebrowser)

enable_testing()

# add_library(imgui SHARED
#     3rdparty/imgui/imgui_demo.cpp
#     3rdparty/imgui/imgui_draw.cpp
#     3rdparty/imgui/imgui_tables.cpp
#     3rdparty/imgui/imgui_widgets.cpp
#     3rdparty/imgui/imgui.cpp

#     3rdparty/imgui/backends/imgui_impl_glfw.cpp
#     3rdparty/imgui/backends/imgui_impl_opengl3.cpp
# )

file(GLOB_RECURSE SRC_FILES "src/**.cpp")
add_library (${PROJECT_NAME} SHARED
    3rdparty/glad/src/gl.c
    
    3rdparty/imgui/imgui_demo.cpp
    3rdparty/imgui/imgui_draw.cpp
    3rdparty/imgui/imgui_tables.cpp
    3rdparty/imgui/imgui_widgets.cpp
    3rdparty/imgui/imgui.cpp
    3rdparty/imgui/backends/imgui_impl_glfw.cpp
    3rdparty/imgui/backends/imgui_impl_opengl3.cpp

    ${SRC_FILES}
    ${CMAKE_JS_SRC}
)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

target_link_libraries(${PROJECT_NAME}
    glfw
    assimp
    freetype
    # imgui
)

set_property (TARGET ${PROJECT_NAME}
  PROPERTY
    # Enable C++20 standard compliance
    CXX_STANDARD 20
)

# Main test

add_executable(${PROJECT_NAME}_test
    # 3rdparty/imgui/imgui_demo.cpp
    # 3rdparty/imgui/imgui_draw.cpp
    # 3rdparty/imgui/imgui_tables.cpp
    # 3rdparty/imgui/imgui_widgets.cpp
    # 3rdparty/imgui/imgui.cpp

    # 3rdparty/imgui/backends/imgui_impl_glfw.cpp
    # 3rdparty/imgui/backends/imgui_impl_opengl3.cpp

    main.cpp
)
target_compile_features(${PROJECT_NAME}_test PUBLIC cxx_std_20)

if (WIN32)
    target_link_libraries(${PROJECT_NAME}_test
        ${PROJECT_NAME}
    )
else()
    target_link_libraries(${PROJECT_NAME}_test
        ${PROJECT_NAME}
        dl
    )
endif (WIN32)

# if (WIN32)
# target_link_libraries(${PROJECT_NAME}_test
#     "D:\\projects\\glwpp\\3rdparty\\VLD\\lib\\Win64\\vld.lib"
# )
# else ()
# target_link_libraries(${PROJECT_NAME}_test
#     ${CMAKE_DL_LIBS}
# )
# endif (WIN32)

# set_property (TARGET ${PROJECT_NAME}_test
#   PROPERTY
#     # Enable C++20 standard compliance
#     CXX_STANDARD 20
# )

# configure_file(shaders/vertex_2d.vs vertex_2d.vs)
# configure_file(shaders/vertex_2d.fs vertex_2d.fs)