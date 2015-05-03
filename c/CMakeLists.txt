cmake_minimum_required(VERSION 3.2)
project(TFA)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g -std=gnu11")

set(SOURCE_FILES
    src/fa.c
    src/fa.h
    src/main.c)

add_executable(TFA ${SOURCE_FILES})