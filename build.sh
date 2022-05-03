#!/bin/bash

clear="$*" #获取环境变量

#清除cmake文件
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
    sudo cp -rf src /usr/include/YqmUtil
    cmake .
    make
    sudo cp -rf lib/libYUtil.so /usr/lib/x86_64-linux-gnu/
}

#卸载
uninstall()
{
    sudo rm -rf /usr/include/YqmUtil
    echo "删除src /usr/include/YqmUtil/"
    sudo rm -rf /usr/lib/x86_64-linux-gnu/libYUtil.so
    echo "删除lib /usr/lib/x86_64-linux-gnu/libYUtil.so"
}

if [ "${clear}" = "clear" ]
then
    clear
elif [ "${clear}" = "uninstall" ]
then 
    uninstall
else
    build
fi