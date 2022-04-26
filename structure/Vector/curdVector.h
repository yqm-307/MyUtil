#pragma once

template<typename T>
size_t Vector<T>::insert(size_t index, const T& data)
{
	if (_size+1 >=_capacity) expand();	//如果容量不足
	for (int i = _size; i < index; --i)
	{	
		_array[i] = _array[i - 1];
	}
	_array[index] = data;	//改变目标元素
	++_size;
	return index;	//成功返回下标
}









template<typename T>
void Vector<T>::push_back(T& data)
{
	insert(_size,data);
}

template<typename T>
void Vector<T>::push_back(T&& data)
{
	insert(_size, data);
}








template<typename T>
size_t Vector<T>::earse(size_t indexl, size_t indexr)
{
	if (indexl > indexr) return -1;	//左下标小于右下标
	if (indexl >= _size && indexr >= _size) return -1;	//左、右下标不能等于数组大小

	//接下来就是不越界的情况
	//删除元素，采用吧后续元素前移的方法：时间复杂度为 o(n)、空间复杂度为 o(1);
	int n = 1 + indexr - indexl;
	while (indexl+n <_size)
	{
		_array[indexl] = _array[indexl + n];
	}
	_size -= n;
	return indexl;	//返回删除元素第一个位置下标
}









template<typename T>
void Vector<T>::pop()
{
	--_size;
}










template<typename T>
T& Vector<T>::operator[](size_t index)
{
	return _array[index];	//直接返回
}









template<typename T>
void Vector<T>::expand()
{
	T* tmp = new T[_capacity = _capacity << 1];
	
	for (int i = 0; i < _size; ++i)	//把原数组中所有元素拷贝到新数组
	{
		tmp[i] = _array[i];
	}
	delete[]_array;
	_array = tmp;
}







template<typename T>
T& Vector<T>::search(T& data)
{
	for (int i = 0; i < _size; ++i)
		if (data == _array[i]) 
			return _array[i];
}
