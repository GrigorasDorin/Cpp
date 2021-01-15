cmake_minimum_required(VERSION 3.3)
project(Code LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_library(message STATIC message.h message.cpp)
add_library(grid STATIC 
    grid.h grid.cpp
    board.h board.cpp)
add_library(error STATIC
    error.h error.cpp
    error_corelation.h error_corelation.cpp)
add_executable(code.out main.cpp)

target_link_libraries(code.out message grid error)