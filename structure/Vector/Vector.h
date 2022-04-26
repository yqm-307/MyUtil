#pragma once

#define INITSIZE 8


//Ҫ������Ԫ������ѭ�ϸ������
/*
	���ʱ���Ѵ��������������ߣ�������㷨�ǲ������ⲿ�ĵ����Ƿ������߽����⣬�ɵ����ߴ���
*/
template<typename T>
class Vector
{
public:
	Vector();
	Vector(size_t, const T& tmp);
	~Vector();
	//Vector(const Vector& data);
	Vector<T>& operator=(const Vector& data);
public:
	size_t size() { return _size; };		//����size
	bool empty() { return !_size; };
	void clear();					//���

	//��ɾ�Ĳ�
	T& operator[](size_t index);	//��
	void push_back(T& data);		//��
	void push_back(T&& data);
	size_t earse(size_t indexl,size_t indexr);	//���鷶Χɾ��
	size_t insert(size_t index,const T& data);	//Ԫ���������
	void pop();						//ɾ��β��Ԫ��
	T& search(T& data);				//�飺���ص�һ��ƥ��Ԫ�أ������������䷶Χ����ʵ��ȫ���䷶Χ����

private:
	void expand();					//����

	size_t _size;
	size_t _capacity;
	T* _array;			//�ײ�����

};





#include "initVector.h"
#include "curdVector.h"