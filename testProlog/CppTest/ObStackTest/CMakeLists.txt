cmake_minimum_required(VERSION 3.8)
project(ObStackTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ObStackTest.cpp ObStack.cpp ObStack.h)
add_executable(ObStackTest ${SOURCE_FILES})
