#pragma once

#include <stack>		//DFS
#include <queue>		//BFS



/*		先序遍历		*/
template<typename T>
template<typename FUNC> void TreeNode<T>::preordertrave(TreeNodePtr<T> node, FUNC& func)
{
	if (node == nullptr) return;
	
	func(node);
	if (node->lc)
		preordertrave(node->lc,func);
	if (node->rc)
		preordertrave(node->rc,func);
}










/*		后序遍历		*/
template<typename T>
template<typename FUNC> void TreeNode<T>::postordertrave(TreeNodePtr<T> node,FUNC& func)
{
	if (node == nullptr) return;
	if (node->lc)	postordertrave(node->lc,func);
	if (node->rc)	postordertrave(node->rc,func);
	func(node);
}








/*		中序遍历		*/
template<typename T>
template<typename FUNC> void TreeNode<T>::inordertrave(TreeNodePtr<T> node,FUNC& func)
{
	if (node == nullptr) return;
	if (node->lc)	inordertrave(node->lc,func);
	func(node);
	if (node->rc)	inordertrave(node->rc,func);
}







/*	遍历ADT	*/
template<typename T>
template<typename FUNC>int TreeNode<T>::traverse(int m_mode, FUNC& func)
{
	//func = f;	//设置遍历器

	switch (m_mode)
	{
	case 1:
		this->preordertrave(this,func); break;
	case 2:
		this->inordertrave(this,func); break;
	case 3:
		this->postordertrave(this,func); break;
	default:
		m_mode = -1;
		break;
	}
	return m_mode;
}








/*	子树规模	*/
template<typename T>
int TreeNode<T>::size()											
{
	int ret = 0;
	std::function<void(TreeNode<T>&)> f = [&](TreeNode<T>& node) {static int i = 0; ++i; };
	traverse(1, f);	//中序遍历

}










template<typename T>
TreeNodePtr<T> TreeNode<T>::succ() //取当前节点的直接后继
{
	TreeNodePtr<T> s = this; //记录后继的临时变量
	if (rc) { //若有右孩子，则直接后继必在右子树中，具体地就是
		s = rc; //右子树中
		while (s->lc != nullptr) s = s->lc; //最靠左（最小）的节点
	}
	else { //否则，直接后继应是“将当前节点包含于其左子树中的最低祖先”，具体地就是
		while (s->rc != nullptr) s = s->parent; //逆向地沿右向分支，不断朝左上方移动
		s = s->parent; //最后再朝右上方移动一步，即抵达直接后继（如果存在）
	}
	return s;
}









//深度优先搜索：使用栈进行深度优先搜索，相较于递归实现可以避免栈溢出（也就是爆栈）
template<typename T>
template<typename FUNC>
void TreeNode<T>::DFS(FUNC& func,TreeNodePtr<T> root)
{
	if (!root) root = this;	//如果未设置起始节点，默认为root节点
	std::stack<TreeNodePtr<T>> Stack;	//模拟栈
	Stack.push(root);		//意义上的根节点入栈
	TreeNodePtr<T> p;
	while (!Stack.empty()) {	//栈非空
		p = Stack.top();
		Stack.pop();
		if (!p) continue;//p为空
		//如果p不为空
		func(p);//对p进行FUNC操作
		if (p->rc) {//如果右子树存在
			Stack.push(p->rc);
		}
		if (p->lc) {
			Stack.push(p->lc);
		}
	}
}


template<typename T>
template<typename FUNC>
void TreeNode<T>::BFS(FUNC& func, TreeNodePtr<T> root)
{
	if (!root) root = this;
	std::queue<TreeNodePtr<T>> Queue;
	Queue.push(root);
	TreeNodePtr<T> p;
	while (!Queue.empty()){//队列非空
		p = Queue.front();
		Queue.pop();
		if (!p) continue;
		func(p);
		if (p->rc) {
			Queue.push(p->rc);
		}
		if (p->lc) {
			Queue.push(p->lc);
		}
	}
}