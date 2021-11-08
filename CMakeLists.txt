cmake_minimum_required(VERSION 3.19)
project(abi_guard C CXX)

set(CMAKE_C_STANDARD 99)

find_package(Git)
if (Git_FOUND)
    execute_process(COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
            OUTPUT_VARIABLE GIT_REPO_VERSION
            OUTPUT_STRIP_TRAILING_WHITESPACE)
else ()
    message(WARNING "git not found")
    set(GIT_REPO_VERSION "unknown")
endif ()

message(STATUS "git version ${GIT_REPO_VERSION}")
configure_file("abi_guard_key.in" "abi_guard_key.h")

add_library(abi_guard_example abi_guard.h
        example.c)

target_include_directories(abi_guard_example
        PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

add_executable(abi_guard_demo main.c)

target_link_libraries(abi_guard_demo
        abi_guard_example)

add_executable(abi_guard_cpp_demo cpp.cc)

target_link_libraries(abi_guard_cpp_demo
        abi_guard_example)