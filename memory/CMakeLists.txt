cmake_minimum_required (VERSION 2.6)

option(USE_CLANG "build application with clang" ON) # OFF is the default

if(USE_CLANG)
    set(CMAKE_C_COMPILER "clang")
    set(CMAKE_CXX_COMPILER "clang++")
endif(USE_CLANG)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (memory)
add_executable(memory main.cpp)
