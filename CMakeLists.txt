cmake_minimum_required(VERSION 2.8)

project(YUtil CXX)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")


set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib) 
include_directories(${PROJECT_BINARY_DIR})


set(HPPSRCS
    src/Logger/Logger.h
    src/Logger/Logger.cpp

    src/noncopyable/noncopyable.h

    src/structure/Array/array.h
    src/structure/Array/Basic_Array.h
    src/structure/Array/Simple_Array.h
    src/structure/Array/stack.h
    src/structure/Array/queue.h
    src/structure/Array/Array_NULLCPP.cpp

    src/timer/interval.hpp
    src/timer/timer_NULLCPP.cpp
    src/timer/universal.h

)
add_library(YUtil SHARED ${HPPSRCS})
#install(TARGETS YUtil DESTINATION lib/)

