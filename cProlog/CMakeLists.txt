cmake_minimum_required(VERSION 3.3)
project(cProlog)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    c_src/IntList.cpp
    c_src/IntList.h
    c_src/IntStack.h
    c_src/IntStack_1.cpp
    c_src/main.cpp)

add_executable(cProlog ${SOURCE_FILES})