#pragma once
#include <cstddef>
#include "DListNode.h"


//template<class T>
//using ListNodePtr = ListNode<T>*;
namespace YqmUtil::Structure::List
{



template<class T,class Node = DListNode<T>>
class Basic_List
{
public:
	typedef Node* ListNodePtr;


	Basic_List() {}
	virtual ~Basic_List(){};

public:
	virtual size_t size()=0;
	virtual bool empty()=0;

private:
	int size_;
	ListNodePtr header;
	ListNodePtr trailer;
};











}//namespace end







