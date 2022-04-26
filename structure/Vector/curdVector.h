#pragma once

template<typename T>
size_t Vector<T>::insert(size_t index, const T& data)
{
	if (_size+1 >=_capacity) expand();	//�����������
	for (int i = _size; i < index; --i)
	{	
		_array[i] = _array[i - 1];
	}
	_array[index] = data;	//�ı�Ŀ��Ԫ��
	++_size;
	return index;	//�ɹ������±�
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
	if (indexl > indexr) return -1;	//���±�С�����±�
	if (indexl >= _size && indexr >= _size) return -1;	//�����±겻�ܵ��������С

	//���������ǲ�Խ������
	//ɾ��Ԫ�أ����ðɺ���Ԫ��ǰ�Ƶķ�����ʱ�临�Ӷ�Ϊ o(n)���ռ临�Ӷ�Ϊ o(1);
	int n = 1 + indexr - indexl;
	while (indexl+n <_size)
	{
		_array[indexl] = _array[indexl + n];
	}
	_size -= n;
	return indexl;	//����ɾ��Ԫ�ص�һ��λ���±�
}









template<typename T>
void Vector<T>::pop()
{
	--_size;
}










template<typename T>
T& Vector<T>::operator[](size_t index)
{
	return _array[index];	//ֱ�ӷ���
}









template<typename T>
void Vector<T>::expand()
{
	T* tmp = new T[_capacity = _capacity << 1];
	
	for (int i = 0; i < _size; ++i)	//��ԭ����������Ԫ�ؿ�����������
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
