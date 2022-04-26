#pragma once

#define INITSIZE 8


//要求数据元素是遵循严格弱序的
/*
	设计时，把错误处理留给调用者，在设计算法是不考虑外部的调用是否合理（如边界问题，由调用者处理）
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
	size_t size() { return _size; };		//返回size
	bool empty() { return !_size; };
	void clear();					//清空

	//增删改查
	T& operator[](size_t index);	//改
	void push_back(T& data);		//增
	void push_back(T&& data);
	size_t earse(size_t indexl,size_t indexr);	//数组范围删除
	size_t insert(size_t index,const T& data);	//元素随机插入
	void pop();						//删除尾部元素
	T& search(T& data);				//查：返回第一个匹配元素，方案二：区间范围查找实现全区间范围查找

private:
	void expand();					//扩张

	size_t _size;
	size_t _capacity;
	T* _array;			//底层数组

};





#include "initVector.h"
#include "curdVector.h"