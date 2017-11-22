cmake_minimum_required(VERSION 3.3)
project(cProlog)

set(CMAKE_CXX_STANDARD 11)
set(BOOST_ROOT "C:/boost/boost_1_65_1")
set(BOOST_LIBRARYDIR "C:/boost/boost_1_65_1/libs")
find_package(Boost 1.65.1)

if (Boost_FOUND)
    message("Found boost")
    include_directories(${BOOST_ROOT})
endif ()
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    c_src/IntList.cpp
    c_src/IntList.h
    c_src/IntStack.h
    c_src/IntStack_1.cpp
    c_src/IntMap1.cpp
    c_src/IntMap.h
    c_src/Clause.cpp
    c_src/Clause.h
    c_src/Spine.cpp
    c_src/Spine.h
    c_src/main.cpp
    c_src/IMap.cpp
    c_src/IMap.h)

add_executable(cProlog ${SOURCE_FILES} c_src/IMap.cpp c_src/IMap.h)

if (Boost_FOUND)
    target_link_libraries(cProlog ${BOOST_LIBRARYDIR})
endif()