/**
 * @file DLinkList.hpp
 * @author yqm (979336542@qq.com)
 * @brief 双向链表
 * @version 0.1
 * @date 2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include "Basic_List.h"
#include <functional>

namespace YqmUtil::Structure::List
{
template<typename T,class Node = ListNode<T>>
class DLinkList:public Basic_List<T,Node>
{
public:
    typedef Node NodeType;
    typedef Node* ListNodePtr ; 
public:
    DLinkList()
    {
        header = new ListNode<T>;
        trailer = new ListNode<T>;
        header->pred = nullptr;
        header->succ = trailer;
        trailer->pred = header;
        trailer->succ = nullptr;
        size_ = 0;
    }
    ~DLinkList()
    {
        int ret = size_;
        while (size_)
            this->erase(this->header->succ); //删除直到size为0
    }
    typedef std::function<void(Node*)> TraverseFunc;
	size_t size() { return size_;}
	bool empty() { return !size();}
	virtual ListNodePtr end() { return trailer;}
	virtual ListNodePtr begin() { return header->succ;}

    void push_back(const T& e)
    {
        this->insertAsLast(e);
    }
    void push_front(const T& e)
    {
        this->insertAsFirst(e);
    }
    //移出除尾结点
    void pop_back()
    {
        ListNodePtr tmp = this->trailer->pred->pred;
        this->erase(this->trailer->pred);
    }
    //移出首节点
    void pop_front()
    {
        ListNodePtr tmp = this->header->succ->succ;
        this->erase(this->header->succ);
    }
    //根据位置删除
    void remove(Rank r)
    {
        this->erase(r);
    }
    void remove(ListNodePtr p)
    {
        this->erase(p);
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
    //排序
    void sort(){ merge(this->header->succ,this->size_);}
	virtual ListNodePtr operator[](Rank r) {
		ListNodePtr p = header;
		while( 0 <= r-- ) p = p->succ;
		return p;
	}
    //遍历
    void traverse(TraverseFunc&& func)
    {
        auto p = this->begin();
        while (p!=this->end())
        {
            func(p);
            p = p->succ;
        }
    }
protected:
    void merge(ListNodePtr p,int n)
	{
		if( n < 2 ) return;	//递归基	如果只有1个元素，就开始递归
		int m = n >> 1;	//中点

		ListNodePtr q = p; for( int i = 0; i < m; ++i ) q = q->succ;	//均分列表
		merge(p,m);	merge(q,n - m);
		//归并
		p = Sort(p,m,*this,q,n - m);
	}

	ListNodePtr Sort(ListNodePtr p,int n,Basic_List<T,Node>& L,ListNodePtr q,int m)
	{
		ListNodePtr pp = p->pred;	//归并后，p一定不是原点，因此要记录原点
		//表一和表二，进行一次排序，假设表有序；
		while( m > 0 && q != p ) {	//将q归并到p中，如果剩余的是q则需要移动q的剩余列表；否则，p的剩余，就不需要移动列表
			if( n > 0 && (p->data >= q->data) ) {
				insertBefore(p,L.remove((q = q->succ)->pred)); m--;
			}
			else
			{
				p = p->succ;
				n--;
			}
		}
		return pp->succ;
	}

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
private:
    int size_;
	ListNodePtr header;
	ListNodePtr trailer;
};

}