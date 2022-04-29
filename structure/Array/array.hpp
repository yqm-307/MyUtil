#pragma once
#include "Basic_Array.hpp"

namespace YqmUtil::Structure::Array
{

template<class T>
class array:public Basic_Array<T>
{
public:
    array():_capacity(INITSIZE),size_(0),_array(new T[_capacity]()){}
    //array():size_(0),_capacity(INITSIZE),_array(new T[_capacity]()){};
	array(size_t size):size_(size),_capacity(2*size_),_array(new T[_capacity]){}
	array(size_t size, const T& data) : size_(size), _capacity(2*size),_array(new T[_capacity])
	{
		for (int i = 0; i < size_; ++i)
			_array[i] = data;
	}
    virtual ~array(){delete[] _array;}
	virtual T& operator[](size_t index) { return this->_array[index];}

protected:
    virtual T& search(T& data)
	{
		for (int i = 0; i < this->size_; ++i)
			if (data == this->_array[i])
				return this->_array[i];
	}

};
}