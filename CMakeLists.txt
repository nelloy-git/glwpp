cmake_minimum_required(VERSION 3.1...3.17 FATAL_ERROR)

# if (WIN32)
#     set(CMAKE_CXX_COMPILER C:/MinGW/mingw64-g++-11.2/bin/g++)
#     set(CMAKE_C_COMPILER C:/MinGW/mingw64-g++-11.2/bin/gcc)
# else ()
#     # set(/usr/bin/g++-11)
#     # set(/usr/bin/gcc-11)
# endif (WIN32)

project(glwpp VERSION 0.1 LANGUAGES C CXX)

add_subdirectory(./3rdparty/glfw)

add_compile_definitions(GLWPP_DEBUG)
add_compile_options(-g -O0)

include_directories(./include)
include_directories(./3rdparty/glad/include)
include_directories(./3rdparty/glfw/include)

add_library (${PROJECT_NAME} STATIC
    ./3rdparty/glad/src/gl.c

    ./src/ctx/Context.cpp
    
    ./src/input/Keyboard.cpp
    ./src/input/Mouse.cpp
    ./src/input/System.cpp
    
    ./src/utils/CmdThread.cpp

    ./src/Window.cpp
)

target_link_libraries(${PROJECT_NAME}
    glfw
)

set_property (TARGET ${PROJECT_NAME}
  PROPERTY
    # Enable C++20 standard compliance
    CXX_STANDARD 20
)

add_executable(${PROJECT_NAME}_test
    main.cpp
)

target_link_libraries(${PROJECT_NAME}_test
    glwpp
)

set_property (TARGET ${PROJECT_NAME}_test
  PROPERTY
    # Enable C++20 standard compliance
    CXX_STANDARD 20
)

configure_file(shaders/vertex_2d.vs vertex_2d.vs)
configure_file(shaders/vertex_2d.fs vertex_2d.fs)