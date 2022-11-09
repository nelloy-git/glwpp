cmake_minimum_required(VERSION 3.1...3.17 FATAL_ERROR)

project(glwpp VERSION 0.1 LANGUAGES C CXX)
include_directories(${CMAKE_JS_INC})

if (WIN32)
    # set(CMAKE_CXX_COMPILER C:/MinGW/mingw64-g++-11.2/bin/g++.exe)
    # set(CMAKE_C_COMPILER C:/MinGW/mingw64-g++-11.2/bin/gcc.exe)
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
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest /Zi /W3 /D_DEBUG")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23 -fconcepts -pthread")
endif (WIN32)

include_directories(./src)
include_directories(./3rdparty/assimp/include)
include_directories(./3rdparty/glad/include)
include_directories(./3rdparty/glfw/include)
include_directories(./3rdparty/glm)
include_directories(./3rdparty/magic_enum/include)
include_directories(./3rdparty/thread_pool)
include_directories(./3rdparty/VLD/include)
link_directories(./3rdparty/VLD/lib/Win64)
include_directories(./3rdparty/freetype/include)

file(GLOB_RECURSE SRC_FILES "src/**.cpp")

add_library (${PROJECT_NAME} SHARED
    3rdparty/glad/src/gl.c

    ${SRC_FILES}
    ${CMAKE_JS_SRC}
)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

target_link_libraries(${PROJECT_NAME}
    glfw
    assimp
    freetype
)

set_property (TARGET ${PROJECT_NAME}
  PROPERTY
    # Enable C++23 standard compliance
    CXX_STANDARD 23
)

# Main test

add_executable(${PROJECT_NAME}_test
    main.cpp
)
# target_compile_features(${PROJECT_NAME}_test PUBLIC cxx_std_20)

target_link_libraries(${PROJECT_NAME}_test
    ${PROJECT_NAME}
)

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