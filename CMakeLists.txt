cmake_minimum_required(VERSION 3.9)
project(grandma_turner C)

set(CMAKE_C_STANDARD 99)

add_executable(grandma_turner main.c include/gttypes.h include/gtstack.h src/gtstack.c)