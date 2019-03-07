cmake_minimum_required(VERSION 3.13)
project(parser_arithmetic)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(parser_arithmetic
        equation.cpp
        equation.h
        helper.cpp
        helper.h
        main.cpp)
