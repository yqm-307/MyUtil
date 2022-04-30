#pragma once

#include <stack>		//DFS
#include <queue>		//BFS



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










/*		�������		*/
template<typename T>
template<typename FUNC> void TreeNode<T>::postordertrave(TreeNodePtr<T> node,FUNC& func)
{
	if (node == nullptr) return;
	if (node->lc)	postordertrave(node->lc,func);
	if (node->rc)	postordertrave(node->rc,func);
	func(node);
}








/*		�������		*/
template<typename T>
template<typename FUNC> void TreeNode<T>::inordertrave(TreeNodePtr<T> node,FUNC& func)
{
	if (node == nullptr) return;
	if (node->lc)	inordertrave(node->lc,func);
	func(node);
	if (node->rc)	inordertrave(node->rc,func);
}







/*	����ADT	*/
template<typename T>
template<typename FUNC>int TreeNode<T>::traverse(int m_mode, FUNC& func)
{
	//func = f;	//���ñ�����

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








/*	������ģ	*/
template<typename T>
int TreeNode<T>::size()											
{
	int ret = 0;
	std::function<void(TreeNode<T>&)> f = [&](TreeNode<T>& node) {static int i = 0; ++i; };
	traverse(1, f);	//�������

}










template<typename T>
TreeNodePtr<T> TreeNode<T>::succ() //ȡ��ǰ�ڵ��ֱ�Ӻ��
{
	TreeNodePtr<T> s = this; //��¼��̵���ʱ����
	if (rc) { //�����Һ��ӣ���ֱ�Ӻ�̱����������У�����ؾ���
		s = rc; //��������
		while (s->lc != nullptr) s = s->lc; //�����С���Ľڵ�
	}
	else { //����ֱ�Ӻ��Ӧ�ǡ�����ǰ�ڵ���������������е�������ȡ�������ؾ���
		while (s->rc != nullptr) s = s->parent; //������������֧�����ϳ����Ϸ��ƶ�
		s = s->parent; //����ٳ����Ϸ��ƶ�һ�������ִ�ֱ�Ӻ�̣�������ڣ�
	}
	return s;
}









//�������������ʹ��ջ���������������������ڵݹ�ʵ�ֿ��Ա���ջ�����Ҳ���Ǳ�ջ��
template<typename T>
template<typename FUNC>
void TreeNode<T>::DFS(FUNC& func,TreeNodePtr<T> root)
{
	if (!root) root = this;	//���δ������ʼ�ڵ㣬Ĭ��Ϊroot�ڵ�
	std::stack<TreeNodePtr<T>> Stack;	//ģ��ջ
	Stack.push(root);		//�����ϵĸ��ڵ���ջ
	TreeNodePtr<T> p;
	while (!Stack.empty()) {	//ջ�ǿ�
		p = Stack.top();
		Stack.pop();
		if (!p) continue;//pΪ��
		//���p��Ϊ��
		func(p);//��p����FUNC����
		if (p->rc) {//�������������
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
	while (!Queue.empty()){//���зǿ�
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