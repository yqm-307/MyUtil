cmake_minimum_required(VERSION 2.8)

project(YUtil CXX)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")


set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib) 
include_directories(${PROJECT_BINARY_DIR})


#完全编译
#file(GLOB_RECURSE HPPSRCS src/*.cpp src/*.hpp)
#message(STATUS "${HPPSRCS}")

#日志相关工具
set(YUTIL_LOGGER
src/Logger/Logger.cpp
src/Logger/Logger.h
)

#数组相关
set(YUTIL_ARRAY
src/structure/Array/array.h
src/structure/Array/Basic_Array.h
src/structure/Array/queue.h
src/structure/Array/Simple_Array.h
src/structure/Array/stack.h
)

#链表相关
set(YUTIL_LIST
src/structure/List/Basic_List.h
src/structure/List/DLinkList.h
src/structure/List/DListNode.h
src/structure/List/LQueue.h
src/structure/List/LStack.h
src/structure/List/Pure_ListNode.h
src/structure/List/Pure_Virtual_List.h
)

#时间相关
set(YUTIL_TIMESRC
src/timer/interval.hpp
src/timer/timer_NULLCPP.cpp
src/timer/universal.h
)

#文件相关
set(YUTIL_FILE
src/fileUtil/FileRead.cpp
)

#线程相关
set(YUTIL_THREAD
src/threadpool/Thread.cpp
src/threadpool/Thread.h
src/threadpool/ThreadPool.h
)

set(HPPSRCS
    src/noncopyable/noncopyable.h
    ${YUTIL_LOGGER}
    ${YUTIL_LIST}
    ${YUTIL_FILE}
    ${YUTIL_TIME}
    ${YUTIL_ARRAY}
    ${YUTIL_THREAD}
)


add_library(YUtil SHARED ${HPPSRCS})
#install(TARGETS YUtil DESTINATION lib/)

