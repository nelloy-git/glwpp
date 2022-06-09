cmake_minimum_required(VERSION 3.1...3.17 FATAL_ERROR)

project(glwpp VERSION 0.1 LANGUAGES C CXX)

if (WIN32)
    set(CMAKE_CXX_COMPILER C:/MinGW/mingw64-g++-11.2/bin/g++.exe)
    set(CMAKE_C_COMPILER C:/MinGW/mingw64-g++-11.2/bin/gcc.exe)
else ()
    # set(/usr/bin/g++-11)
    # set(/usr/bin/gcc-11)
endif (WIN32)

enable_testing()

add_subdirectory(./3rdparty/assimp)
add_subdirectory(./3rdparty/glfw)
add_subdirectory(./3rdparty/googletest)
add_subdirectory(./3rdparty/freetype)
add_subdirectory(./test)

add_compile_definitions(GLWPP_DEBUG)
if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi /D_DEBUG")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -fconcepts -pthread")
endif (WIN32)

include_directories(./include)
include_directories(./3rdparty/assimp/include)
include_directories(./3rdparty/glad/include)
include_directories(./3rdparty/glfw/include)
include_directories(./3rdparty/glm)
include_directories(./3rdparty/magic_enum/include)
include_directories(./3rdparty/thread_pool)
include_directories(./3rdparty/VLD/include)
include_directories(./3rdparty/freetype/include)

add_library (${PROJECT_NAME} STATIC
    3rdparty/glad/src/gl.c

    src/ctx/Context.cpp
    
    src/glfw/enums/Action.cpp
    src/glfw/enums/Button.cpp
    src/glfw/enums/Key.cpp
    src/glfw/enums/Mod.cpp
    src/glfw/Window.cpp

    # src/gl/ctx_only/CtxObject.cpp
    # src/gl/ctx_only/CtxBuffer.cpp
    # src/gl/ctx_only/CtxProgram.cpp
    # src/gl/ctx_only/CtxShader.cpp
    # src/gl/ctx_only/CtxTexture.cpp
    # src/gl/ctx_only/CtxVertexArray.cpp

    # src/gl/obj/Object.cpp
    # src/gl/obj/Buffer.cpp
    # src/gl/obj/Program.cpp
    # src/gl/obj/Shader.cpp
    # src/gl/obj/Texture.cpp
    # src/gl/obj/VertexArray.cpp
    
    src/gl/obj/Object.cpp
    src/gl/obj/Buffer.cpp
    src/gl/obj/Shader.cpp
    src/gl/obj/Program.cpp
    src/gl/obj/Texture.cpp
    src/gl/obj/VertexArray.cpp

    # src/ctx/FreeType/Font.cpp

    # src/utils/event/EventStatus.cpp

    # src/drawer/Camera.cpp

    # src/model/Mesh.cpp
    # src/model/MeshAttributeData.cpp
    src/model/MeshIndexData.cpp
    src/model/MeshVertexConfig.cpp
    # src/model/MeshVertexData.cpp
    # src/model/ModelNode.cpp

    # src/Drawer.cpp
)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

target_link_libraries(${PROJECT_NAME}
    glfw
    assimp
    freetype
)

set_property (TARGET ${PROJECT_NAME}
  PROPERTY
    # Enable C++20 standard compliance
    CXX_STANDARD 20
)

# Main test

add_executable(${PROJECT_NAME}_test
    main.cpp
)
target_compile_features(${PROJECT_NAME}_test PUBLIC cxx_std_20)

target_link_libraries(${PROJECT_NAME}_test
    glwpp
)

if (WIN32)
target_link_libraries(${PROJECT_NAME}_test
    "D:\\projects\\glwpp\\3rdparty\\VLD\\lib\\Win64\\vld.lib"
)
else ()
target_link_libraries(${PROJECT_NAME}_test
    ${CMAKE_DL_LIBS}
)
endif (WIN32)

set_property (TARGET ${PROJECT_NAME}_test
  PROPERTY
    # Enable C++20 standard compliance
    CXX_STANDARD 20
)

# configure_file(shaders/vertex_2d.vs vertex_2d.vs)
# configure_file(shaders/vertex_2d.fs vertex_2d.fs)