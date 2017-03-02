cmake_minimum_required(VERSION 3.6)
project(Example___Fractions)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Fraction.cpp
        Fraction.h
        Main.cpp)

add_executable(Example___Fractions ${SOURCE_FILES})