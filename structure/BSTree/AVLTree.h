#pragma once

#include "Node.h"
/*	反正都是造轮子了，造个好一点的，AVL树	*/


//二叉树
template<typename T>
class AVLTree
{
public:
	AVLTree() :_parent(nullptr),_size(0), _root(nullptr) {};
	AVLTree(TreeNodePtr<T> root) :_root(root){ _size = root ? 1 : 0; };
	~AVLTree();


public:	/*对外接口*/
	//节点数
	int size() const { return _size; }
	//判空
	bool empty() const { return !_size; }
	//获取根节点
	TreeNodePtr<T> root() const { return _root; }

	TreeNodePtr<T> insert(const T& e);						//将新节点插入树中
	bool remove(const T& e);								//删除目标值
	TreeNodePtr<T>& search(const T&);						//查找目标值，查找失败返回nullptr
	TreeNodePtr<T>& search(T&& e) { this->search(std::forward<T&>(e)); }
	TreeNodePtr<T>& search(const TreeNode<T>& node) { return this->search(node.data); }					//查询
	template<typename FUNC>int traverse(int m_mode, FUNC& f) { return _root->traverse(m_mode, f); }		//遍历
	template<typename FUNC>void DFS(FUNC& f) { _root->DFS(f); }		//深度优先搜索
	template<typename FUNC>void BFS(FUNC& f) { _root->BFS(f); }		//广度优先搜索


private:
	int updataHeight(TreeNodePtr<T> ptr);										//当前子树高度
	void updataHeightAnc(TreeNodePtr<T> ptr);									//更新全树高度
	TreeNodePtr<T> connect34(TreeNodePtr<T>, TreeNodePtr<T>, TreeNodePtr<T>,
		TreeNodePtr<T>, TreeNodePtr<T>, TreeNodePtr<T>, TreeNodePtr<T>);		//统一重平衡
	TreeNodePtr<T> rotateAt(TreeNodePtr<T> node);								//根据如何旋转给统一重平衡器以特定顺序传参
	//TreeNodePtr<T> findParentNode(const T&& e);								//寻找插入位置的父节点	有了_parent就不需要这个接口了
	TreeNodePtr<T> _parent;														//在每次搜索之中维护它，如果在频繁发生增删的时候，效率比findParentNode(e)高
private:
	TreeNodePtr<T> _root;
	int _size;
};



/*	可以使用宏定义，个人习惯用inline，不超过10行，符合inline标准	*/
//两者平衡因子相同
template<typename T>
inline bool  Balanced(const TreeNode<T>& x) { return (x.lc->status() == x.rc->status()); }	
//当前平衡因子
template<typename T>
inline int BalFac(const TreeNode<T>& x) { return (((x.lc)?x.lc->height:-1)-((x.rc)?x.rc->height:-1)); }
//是否平衡
template<typename T>
inline bool AvlBalanced(const TreeNode<T>& x) { return (-2 < BalFac(x) && 2 > BalFac(x)); }	



#include "curd.h"
#include "AVLinit.h"