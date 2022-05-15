cmake_minimum_required(VERSION 2.8)

project(YUtil CXX)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")


set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib) 
include_directories(${PROJECT_BINARY_DIR})


file(GLOB_RECURSE HPPSRCS src/*.cpp src/*.hpp)
message(STATUS "${HPPSRCS}")

add_library(YUtil SHARED ${HPPSRCS})
#install(TARGETS YUtil DESTINATION lib/)

