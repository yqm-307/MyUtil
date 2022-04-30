#pragma once


namespace YqmUtil::Structure::List
{

typedef int Rank;		//秩
template<class T>
struct ListNode;



template<class T>
struct ListNode	//以双向链表实现为例
{
public:
	ListNode() {}		 //构造一个空的节点
	ListNode(T a,ListNode* p = nullptr,ListNode* s = nullptr)
		: data(a),pred(p),succ(s) {}						//构造一个新的节点，可以不设置后继、前继，默认为空

	virtual ListNode* insertAsSucc(const T& e)		//将s更改为this后继
	{
		ListNode* p = new ListNode<T>(e,this,this->succ);	//新节点，头为当前节点
		this->succ->pred = p; this->succ = p;		//更改当前节点后继指向
		return p;
	}
	virtual ListNode* insertAsPred(const T& e)		//将p更改为this前继
	{
		ListNode* p = new ListNode(e,this->pred,this);	//新建节点前继指向
		this->pred->succ = p; this->pred = p;	//更新关联前后继
		return p;
	}
public:
	T data;	//数据
	ListNode* succ;//后继
	ListNode* pred;//前驱
};
}