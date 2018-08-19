cmake_minimum_required(VERSION 3.2.2)

option(USE_CLANG "build application with clang" ON)

if(USE_CLANG)
    set(CMAKE_C_COMPILER "/usr/bin/clang")
    set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
endif(USE_CLANG)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (thread)
add_executable(mutex main.cpp)
target_link_libraries(mutex -lpthread)
