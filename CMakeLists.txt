cmake_minimum_required(VERSION 3.29)
project(LAB1_MAIN)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB1_MAIN main.cpp
        Point.h
        Symbol.cpp
        Symbol.h
        Line.cpp
        Line.h
        AppManager.cpp
        AppManager.h
        Point.cpp
        ColorManager.cpp
        ColorManager.h
        Terminal.cpp
        Terminal.h
        InputHandler.cpp
        InputHandler.h
        CommandLineParser.cpp
        CommandLineParser.h
        Figure.cpp
        Figure.h
        Explosion.cpp
        Explosion.h
        List.h
        LinkedList.h
        ArrayList.h
)
