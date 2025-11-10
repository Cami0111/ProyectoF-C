cmake_minimum_required(VERSION 4.0)
project(ProyectoFC)

set(CMAKE_CXX_STANDARD 20)

add_executable(proy main.cpp
        criatura.cpp
        criatura.h
        Albo.cpp
        Albo.h
        Metamorfita.cpp
        Metamorfita.h
        Centella.cpp
        Centella.h
        Raiz.cpp
        Raiz.h
        Mundo.cpp
        Mundo.h)
