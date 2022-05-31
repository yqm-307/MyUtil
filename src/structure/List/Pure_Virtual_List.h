#pragma once
#include "Pure_ListNode.h"

namespace YUtil::Structure::List
{

template<class T,class Node = PureListNode<T>>
class PureVirtualList
{
public:
	typedef Node* ListNodePtr;


	PureVirtualList() {}
	virtual ~PureVirtualList()=0;

public:
	virtual size_t size()=0;
	virtual bool empty()=0;
	//尾元素的后一个
	virtual ListNodePtr end()=0;
	//首元素
	virtual ListNodePtr begin()=0;
};

}