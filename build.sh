#!/bin/bash

clear="$*" #获取环境变量

clear()
{
    rm -rf CMakeFiles
    rm *cmake*
    rm CMakeCache.txt
    rm Makefile
    rm -rf lib
    rm log.txt
    rm config.json
}

build()
{
    #编译整个项目目录
    #mkdir bin
    mkdir lib
    cmake .
    make
}

if [ "${clear}" = "clear" ]
then
    clear
else
    build
fi