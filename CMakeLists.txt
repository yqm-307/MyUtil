cmake_minimum_required(VERSION 2.6)

project(YUtil CXX)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")


set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib) 
include_directories(${PROJECT_BINARY_DIR})

file(GLOB HPPSRCS 
    ${PROJECT_BINARY_DIR}/src/structure/*.h 
    ${PROJECT_BINARY_DIR}/src/structure/*.cpp 
    ${PROJECT_BINARY_DIR}/src/timer/*.h
    ${PROJECT_BINARY_DIR}/src/timer/*.cpp
    )    #获取所有hpp文件

add_library(YUtil STATIC ${HPPSRCS})

#install(TARGETS YUtil DESTINATION lib/)

