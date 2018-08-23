cmake_minimum_required(VERSION 3.2.2)

option(USE_CLANG "build application with clang" ON)

if(USE_CLANG)
    set(CMAKE_C_COMPILER "/usr/bin/clang")
    set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
endif(USE_CLANG)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_C_FLAGS "-Wc++17-extensions")
# SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wc++17-extensions")


project (multiplereturn)
add_executable(multiplereturn main.cpp)
