/**
 * @file Basic_Array.hpp
 * @author yqm-307 (979336542@qq.com)
 * @brief 基础数组
 * @version 0.1
 * @date 2022-04-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <stdio.h>


namespace YqmUtil::Structure::Array
{
#define INITSIZE 8

template<typename T>
class Basic_Array
{
public:

	Basic_Array(){};
	Basic_Array(size_t size){};
	Basic_Array(size_t size, const T& data){};
	virtual ~Basic_Array(){}
	//array(const array& data);
	
public:
	virtual size_t size()=0; 		
	virtual bool empty()=0;
	virtual void clear()=0;

protected:
	virtual void expand()=0;
	virtual size_t earse(size_t indexl,size_t indexr)=0;
	virtual size_t insert(size_t index,const T& data)=0;
private:
	size_t size_;
	size_t _capacity;
	T* _array;			

};

}



