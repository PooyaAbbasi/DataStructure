cmake_minimum_required(VERSION 3.23)
project(untitled3)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled3 main.cpp
        Stack_int.cpp
        Stack_int.h
        Stack_char.cpp
        Stack_char.h
        ExpressionEvaluator.h
        ExpressionEvaluator.cpp
        recursion.h
        recursion.cpp
)
