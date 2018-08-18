cmake_minimum_required(VERSION 3.2.2)

option(USE_CLANG "build application with clang" ON)

if(USE_CLANG)
    set(CMAKE_C_COMPILER "/usr/bin/clang")
    set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
endif(USE_CLANG)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (genericlambda)
add_executable(genericlambda main.cpp)
