cmake_minimum_required(VERSION 3.1...3.17 FATAL_ERROR)

project(glwpp VERSION 0.1 LANGUAGES C CXX)

# if (WIN32)
#     set(CMAKE_CXX_COMPILER C:/MinGW/mingw64-g++-11.2/bin/g++.exe)
#     set(CMAKE_C_COMPILER C:/MinGW/mingw64-g++-11.2/bin/gcc.exe)
# else ()
#     set(/usr/bin/g++-11)
#     set(/usr/bin/gcc-11)
# endif (WIN32)

enable_testing()

add_subdirectory(./3rdparty/glfw)
add_subdirectory(./3rdparty/googletest)
add_subdirectory(./test)

add_compile_definitions(GLWPP_DEBUG)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi /D_DEBUG")

include_directories(./include)
include_directories(./3rdparty/glad/include)
include_directories(./3rdparty/glfw/include)
include_directories(./3rdparty/thread_pool)
include_directories(./3rdparty/VLD/include)

add_library (${PROJECT_NAME} STATIC
    ./3rdparty/glad/src/gl.c

    ./src/ctx/Context.cpp
    
    # ./src/utils/CmdLoop.cpp

    # ./src/Window.cpp
    src/gl/api/gl_10.cpp
    src/gl/api/gl_11.cpp
    src/gl/api/gl_12.cpp
    src/gl/api/gl_13.cpp
    src/gl/api/gl_14.cpp
    src/gl/api/gl_15.cpp
    src/gl/api/gl_20.cpp
    src/gl/api/gl_21.cpp
    src/gl/api/gl_30.cpp
    src/gl/api/gl_31.cpp
    src/gl/api/gl_32.cpp
    src/gl/api/gl_33.cpp
    src/gl/api/gl_40.cpp
    src/gl/api/gl_41.cpp
    src/gl/api/gl_42.cpp
    src/gl/api/gl_43.cpp
    src/gl/api/gl_44.cpp
    src/gl/api/gl_45.cpp
    src/gl/api/gl_46.cpp
    src/gl/api/types.cpp
    
    src/glfw/enums/Action.cpp
    src/glfw/enums/Button.cpp
    src/glfw/enums/Key.cpp
    src/glfw/enums/Mod.cpp
    src/glfw/Window.cpp

    src/gl/oop/RawBuffer.cpp
)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

target_link_libraries(${PROJECT_NAME}
    glfw
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
    "D:\\projects\\glwpp\\3rdparty\\VLD\\lib\\Win64\\vld.lib"
)

set_property (TARGET ${PROJECT_NAME}_test
  PROPERTY
    # Enable C++20 standard compliance
    CXX_STANDARD 20
)

# configure_file(shaders/vertex_2d.vs vertex_2d.vs)
# configure_file(shaders/vertex_2d.fs vertex_2d.fs)