cmake_minimum_required(VERSION 3.1...3.17 FATAL_ERROR)

project(glwpp VERSION 0.1 LANGUAGES C CXX)

if (WIN32)
    set(CMAKE_CXX_COMPILER C:/MinGW/mingw64-g++-11.2/bin/g++.exe)
    set(CMAKE_C_COMPILER C:/MinGW/mingw64-g++-11.2/bin/gcc.exe)
else ()
    set(/usr/bin/g++-11)
    set(/usr/bin/gcc-11)
endif (WIN32)

option(DEBUG_GLAD "Use glad debug." OFF)


add_subdirectory(./3rdparty/glfw)


include_directories(./glfw/include)
include_directories(./include)
if (DEBUG_GLAD)
    include_directories(./glad4.6_debug/include)
else()
    include_directories(./glad4.6_release/include)
endif(DEBUG_GLAD)


add_library (${PROJECT_NAME} STATIC
    # ./glw/Array.cpp
    # ./glw/Buffer.cpp
    # ./glw/Program.cpp
    # ./glw/Shader.cpp
    # ./glw/Tex2D.cpp
    
    ./src/Context/Keyboard.cpp
    ./src/Context/Mouse.cpp
    ./src/Context/Timer.cpp
    ./src/Context/Window.cpp

    ./src/Context/glfw/Convert.cpp
)

target_link_libraries(${PROJECT_NAME}
    glfw
)

set_property (TARGET ${PROJECT_NAME}
  PROPERTY
    # Enable C++20 standard compliance
    CXX_STANDARD 20
)