#pragma once
#include "Basic_Array.h"
#include <string.h>

namespace YUtil::Structure::Array
{

template<class T>
class Simple_Array:public Basic_Array<T>
{
public:
	Simple_Array():size_(0),_capacity(INITSIZE),_array(new T[_capacity]()){};
    virtual ~Simple_Array(){delete[] _array;}

	virtual size_t size(){ return size_; }
	virtual bool empty() { return !size_; }
	virtual void clear() { size_ = 0;}
	virtual T& operator[](size_t index) { return _array[index];}
protected:
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
        shrink();   //是否缩容
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
    virtual void shrink()
    {
        if(size_ <= _capacity>>2)
        {//如果小于25%，则缩小为50%
            auto newspace = new T[_capacity = _capacity>>1]();
            for (size_t i = 0; i < size_; i++)
                newspace[i] = _array[i];
            delete[] _array;
            _array = newspace;
        }
        else
            return;

    }
protected:
    size_t size_;
	size_t _capacity;
	T* _array;		

};


}