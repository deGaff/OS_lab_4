cmake_minimum_required(VERSION 3.20)
project(l4_2_R)

set(CMAKE_CXX_STANDARD 17)

add_executable(l4_2_R main.cpp safe_input.cpp safe_input.h menu.cpp menu.h)
