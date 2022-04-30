#pragma once
#include <cstddef>
#include "DefaultListNode.h"


//template<class T>
//using ListNodePtr = ListNode<T>*;
namespace YqmUtil::Structure::List
{



template<class T,class Node = ListNode<T>>
class Basic_List
{
public:
	typedef Node* ListNodePtr;


	Basic_List() {
		init();
	}
	virtual ~Basic_List();

public:
	size_t size() { return size_;}
	bool empty() { return !size();}
	//尾元素的后一个
	virtual ListNodePtr end() { return trailer;}
	//首元素
	virtual ListNodePtr begin() { return header->succ;}

	virtual int clear();


	virtual ListNodePtr operator[](Rank r) {
		ListNodePtr p = header;
		while( 0 <= r-- ) p = p->succ;
		return p;
	}

	virtual ListNodePtr find(const T& e)
	{
		auto ptr = begin();
		while(ptr->data != e && ptr !=end())
			ptr = ptr->succ;
		return ptr;
	}
protected:
	virtual void init();

	//插入首元素
	virtual ListNodePtr insertAsFirst(const T& e)
	{
		size_++; return header->insertAsSucc(e);
	}
	//插入尾元素
	virtual ListNodePtr insertAsLast(const T& e)
	{
		size_++; return trailer->insertAsPred(e);
	}
	//在p前方插入e
	virtual ListNodePtr insertBefore(ListNodePtr p,const T& e)
	{
		++size_;
		return p->insertAsPred(e);
	}
	//在p后方插入e
	virtual ListNodePtr insertLater(ListNodePtr p,const T& e)
	{
		++size_;		//更新规模
		return p->insertAsSucc(e);
	}
	virtual T erase(Rank r)
	{//移除指定位置节点
		--size_;
		ListNodePtr p = (*this)[r];
		T data_ = p->data;
		p->pred->succ = p->succ;
		p->succ->pred = p->pred;
		delete p;
		return data_;
	}

	virtual T erase(ListNodePtr p)
	{
		T ret = p->data;
		//改变指向，释放删除节点
		p->succ->pred = p->pred;
		p->pred->succ = p->succ;
		--size_;
		delete p;
		return ret;
	}

protected:
	int size_;
	ListNodePtr header;
	ListNodePtr trailer;
};



template<class T,class Node>
Basic_List<T,Node>::~Basic_List()
{
	clear();
	delete header; delete trailer;
}


template<class T,class Node>
int Basic_List<T,Node>::clear() {
	int ret = size_;
	while( size_ )
		this->erase(this->header->succ);	//删除直到size为0
	return ret;
}


template<class T,class Node>
void Basic_List<T,Node>::init() {
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	header->pred = nullptr; header->succ = trailer;
	trailer->pred = header;	trailer->succ = nullptr;
	size_ = 0;
}


}//namespace end







