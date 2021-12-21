cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)

enable_testing()
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_compile_definitions(GLWPP_DEBUG)

include(GoogleTest)
include_directories(../include)

function(register_test test_name test_path)
    add_executable(${test_name} ${test_path})
    target_compile_features(${test_name} PUBLIC cxx_std_20)
    target_link_libraries(${test_name} gtest_main glwpp)
    gtest_discover_tests(${test_name})
endfunction()

# register_test(test_Watcher utils/event/test_Watcher.cpp)
# register_test(test_Runner utils/event/test_Runner.cpp)
# register_test(test_CmdLoop utils/event/test_CmdLoop.cpp)