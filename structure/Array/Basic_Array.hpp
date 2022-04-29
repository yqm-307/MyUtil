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

	Basic_Array();
	Basic_Array(size_t size);
	Basic_Array(size_t size, const T& data);
	virtual ~Basic_Array()=0;

	//array(const array& data);
	Basic_Array<T>& operator=(const Basic_Array& data)
	{
		delete[] this->_array;
		this->_array = new T[data.size() * 2];

		for (int i = 0; i < data.size(); ++i)
		{
			this->_array[i] = data[i];
		}
		size_ = data.size();
		return *this;
	}
public:
	size_t size() { return size_; }		
	bool empty() { return !size_; }
	void clear() { size_ = 0;}					

	virtual void push_back(T& data) { insert(size_,data);}		
	virtual void push_back(T&& data) { insert(size_,data);}	
	virtual void pop_back(){size_--;}					

protected:
	//扩容
	virtual void expand()
	{
		T* tmp = new T[_capacity = _capacity << 1];
	
		for (int i = 0; i < size_; ++i)	
			tmp[i] = _array[i];
		
		delete[]_array;
		_array = tmp;
	}
	virtual size_t earse(size_t indexl,size_t indexr)
	{
		if (indexl > indexr) return -1;	
		if (indexl >= size_ && indexr >= size_) return -1;	

		int n = 1 + indexr - indexl;
		while (indexl+n <size_)
		{
			_array[indexl] = _array[indexl + n];
		}
		size_ -= n;
		return indexl;	
	}
	virtual size_t insert(size_t index,const T& data)
	{
		if (size_+1 >=_capacity) expand();
		for (int i = size_; i < index; --i)
		{	
			_array[i] = _array[i - 1];
		}
		_array[index] = data;
		++size_;
		return index;
	}	

	size_t size_;
	size_t _capacity;
	T* _array;			

};

}



