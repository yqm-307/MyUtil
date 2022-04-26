#pragma once
#include <cstddef>
#include "DefaultListNode.hpp"


template<class T>
using ListNodePtr = ListNode<T>*;



template<class T,class Node = ListNode<T>>
class Basic_List
{
	
public:
	Basic_List() {
		init();
	}
	~Basic_List();

public:
	size_t size() { return _size;}
	bool empty() { return !size();}
	virtual ListNodePtr<T> end() { return trailer->pred;}
	virtual ListNodePtr<T> begin() { return header->succ;}

	virtual int clear();


	virtual ListNodePtr<T> operator[](Rank r) {
		ListNodePtr<T> p = header;
		while( 0 <= r-- ) p = p->succ;
		return p;
	}

protected:
	virtual void init();

	virtual ListNodePtr<T> insertAsFirst(const T& e)
	{
		_size++; return header->insertAsSucc(e);
	}

	virtual ListNodePtr<T> insertAsLast(const T& e)
	{
		_size++; return trailer->insertAsPred(e);
	}

	virtual ListNodePtr<T> insertBefore(ListNodePtr<T> p,const T& e)
	{
		++_size;
		return p->insertAsPred(e);
	}

	virtual ListNodePtr<T> insertLater(ListNodePtr<T> p,const T& e)
	{
		++_size;		//更新规模
		return p->insertAsSucc(e);
	}
	virtual T earse(Rank r)
	{//移除指定位置节点
		--_size;
		ListNodePtr<T> p = (*this)[r];
		T data_ = p->data;
		p->pred->succ = p->succ;
		p->succ->pred = p->pred;
		delete p;
		return data_;
	}

	virtual T erase(ListNodePtr<T> p)
	{
		T ret = p->data;
		//改变指向，释放删除节点
		p->succ->pred = p->pred;
		p->pred->succ = p->succ;
		--_size;
		delete p;
		return ret;
	}

protected:
	int _size;
	ListNodePtr<T> header;
	ListNodePtr<T> trailer;
};



template<class T,class Node>
Basic_List<T,Node>::~Basic_List()
{
	clear();
	delete header; delete trailer;
}


template<class T,class Node>
int Basic_List<T,Node>::clear() {
	int ret = _size;
	while( _size )
		remove(header->succ);	//删除直到size为0
	return ret;
}


template<class T,class Node>
void Basic_List<T,Node>::init() {
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	header->pred = nullptr; header->succ = trailer;
	trailer->pred = header;	trailer->succ = nullptr;
	_size = 0;
}












