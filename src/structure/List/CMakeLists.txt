

project(test CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")

set(SRCFILE
    Basic_List.hpp
    DefaultListNode.hpp
    DLinkList.hpp
    MainTest.cpp    
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

add_executable(test ${SRCFILE})
set_target_properties(test PROPERTIES LINKER_LANGUAGE CXX)
