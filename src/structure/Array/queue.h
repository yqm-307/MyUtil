/**
 * @file queue.hpp
 * @author yqm-307 (979336542@qq.com)
 * @brief 数组队列
 * @version 0.1
 * @date 2022-04-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include "Simple_Array.h"


//deque实现方式
namespace YqmUtil::Structure::Array
{

template<class T>
class queue: public Simple_Array<T>
{
public:
    void pop() //出队
    {
        this->earse();
    }
    T& front(); //取队首
    void push(T&);  //入队
    void push(T&&);  //入队

};


}