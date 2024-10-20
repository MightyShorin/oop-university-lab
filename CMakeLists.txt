cmake_minimum_required(VERSION 3.29)
project(LAB1_MAIN)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB1_MAIN main.cpp
        Console.h
        Point.h
        Symbol.cpp
        Symbol.h
        Line.cpp
        Line.h
        AppManager.cpp
        AppManager.h
)
