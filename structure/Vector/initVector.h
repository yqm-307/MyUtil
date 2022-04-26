#pragma once


template<typename T>
Vector<T>::Vector():_capacity(INITSIZE),_size(0),_array(new T[_capacity]()){}//构造完毕


template<typename T>
Vector<T>::Vector(size_t size, const T& data) : _size(size), _capacity(2*size),_array(new T[_capacity])
{
	for (int i = 0; i < _size; ++i)
		_array[i] = data;
}//构造完成



//清除数组元素：策略就是改变size
template<typename T>
void Vector<T>::clear()
{
	_size = 0;
}

template<typename T>
Vector<T>::~Vector()
{
	_size = 0;
	_capacity = 0;
	delete[] _array;
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& data)
{
	delete[] this->_array;	//释放原空间
	this->_array = new T[data.size() * 2];

	for (int i = 0; i < data.size(); ++i)	//拷贝新空间元素
	{
		this->_array[i] = data[i];
	}
	_size = data.size();
	return *this;
}
