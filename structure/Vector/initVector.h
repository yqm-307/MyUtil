#pragma once


template<typename T>
Vector<T>::Vector():_capacity(INITSIZE),_size(0),_array(new T[_capacity]()){}//�������


template<typename T>
Vector<T>::Vector(size_t size, const T& data) : _size(size), _capacity(2*size),_array(new T[_capacity])
{
	for (int i = 0; i < _size; ++i)
		_array[i] = data;
}//�������



//�������Ԫ�أ����Ծ��Ǹı�size
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
	delete[] this->_array;	//�ͷ�ԭ�ռ�
	this->_array = new T[data.size() * 2];

	for (int i = 0; i < data.size(); ++i)	//�����¿ռ�Ԫ��
	{
		this->_array[i] = data[i];
	}
	_size = data.size();
	return *this;
}
