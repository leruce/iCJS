cmake_minimum_required(VERSION 3.8)
project(IntStackS)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
set(SOURCE_FILES main.cpp Tests/IntStack.h Tests/test.cpp Tests/IntStack_1.cpp)
add_executable(IntStackS ${SOURCE_FILES} Tests/test.cpp)

target_link_libraries(IntStackS gtest gtest_main)