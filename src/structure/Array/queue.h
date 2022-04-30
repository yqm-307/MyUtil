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



namespace YqmUtil::Structure::Array
{

//思考再三需要用deque实现最佳，或者链表。STL中deque是非常复杂的，不连续空间，还需要中控器管理分段空间的映射关系。所以考虑采用双数组的方法模拟一个队列
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