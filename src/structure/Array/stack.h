/**
 * @file queue.hpp
 * @author yqm-307 (979336542@qq.com)
 * @brief 数组栈
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


template<class T>
class stack: public Simple_Array<T>
{
public:
    void pop() {this->earse(this->size_-1,this->size_-1);}
    T& top() {return this->_array[this->size_-1];}
    void push(T&data) { insert(this->size_,data);}
    void push(T&&data) { push(data);}
};


}