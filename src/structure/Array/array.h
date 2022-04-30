#pragma once
#include "Basic_Array.h"

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

	virtual size_t size(){ return size_; }
	virtual bool empty() { return !size_; }
	virtual void clear() { size_ = 0;}					

	virtual void push_back(T& data) { insert(size_,data);}
	virtual void push_back(T&& data) { insert(size_,data);}	
	virtual void pop_back(){size_--;}			

    virtual ~array(){delete[] _array;}
	virtual T& operator[](size_t index) { return _array[index];}
	array<T>& operator=(const array<T>& data)
	{
		delete[] _array;
		_array = new T[data.size() * 2];

		for (int i = 0; i < data.size(); ++i)
		{
			_array[i] = data[i];
		}
		size_ = data.size();
		return *this;
	}
protected:
    virtual T& search(T& data)
	{
		for (int i = 0; i < size_; ++i)
			if (data == _array[i])
				return _array[i];
	}
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
private:
	size_t size_;
	size_t _capacity;
	T* _array;
};
}