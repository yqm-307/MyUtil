#pragma once

#include "Node.h"
#pragma once


//������
template<typename T>
class AVLTree
{
public:
	AVLTree() :_parent(nullptr),_size(0), _root(nullptr) {};
	AVLTree(TreeNodePtr<T> root) :_root(root){ _size = root ? 1 : 0; };
	~AVLTree();


public:	/*����ӿ�*/
	//�ڵ���
	int size() const { return _size; }
	//�п�
	bool empty() const { return !_size; }
	//��ȡ���ڵ�
	TreeNodePtr<T> root() const { return _root; }

	TreeNodePtr<T> insert(const T& e);						//���½ڵ��������
	bool remove(const T& e);								//ɾ��Ŀ��ֵ
	TreeNodePtr<T>& search(const T&);						//����Ŀ��ֵ������ʧ�ܷ���nullptr
	TreeNodePtr<T>& search(T&& e) { this->search(std::forward<T&>(e)); }
	TreeNodePtr<T>& search(const TreeNode<T>& node) { return this->search(node.data); }					//��ѯ
	template<typename FUNC>int traverse(int m_mode, FUNC& f) { return _root->traverse(m_mode, f); }		//����
	template<typename FUNC>void DFS(FUNC& f) { _root->DFS(f); }		//�����������
	template<typename FUNC>void BFS(FUNC& f) { _root->BFS(f); }		//�����������


private:
	int updataHeight(TreeNodePtr<T> ptr);										//��ǰ�����߶�
	void updataHeightAnc(TreeNodePtr<T> ptr);									//����ȫ���߶�
	TreeNodePtr<T> connect34(TreeNodePtr<T>, TreeNodePtr<T>, TreeNodePtr<T>,
		TreeNodePtr<T>, TreeNodePtr<T>, TreeNodePtr<T>, TreeNodePtr<T>);		//ͳһ��ƽ��
	TreeNodePtr<T> rotateAt(TreeNodePtr<T> node);								//���������ת��ͳһ��ƽ�������ض�˳�򴫲�
	//TreeNodePtr<T> findParentNode(const T&& e);								//Ѱ�Ҳ���λ�õĸ��ڵ�	����_parent�Ͳ���Ҫ����ӿ���
	TreeNodePtr<T> _parent;														//��ÿ������֮��ά�����������Ƶ��������ɾ��ʱ��Ч�ʱ�findParentNode(e)��
private:
	TreeNodePtr<T> _root;
	int _size;
};



/*	����ʹ�ú궨�壬����ϰ����inline��������10�У�����inline��׼	*/
//����ƽ��������ͬ
template<typename T>
inline bool  Balanced(const TreeNode<T>& x) { return (x.lc->status() == x.rc->status()); }	
//��ǰƽ������
template<typename T>
inline int BalFac(const TreeNode<T>& x) { return (((x.lc)?x.lc->height:-1)-((x.rc)?x.rc->height:-1)); }
//�Ƿ�ƽ��
template<typename T>
inline bool AvlBalanced(const TreeNode<T>& x) { return (-2 < BalFac(x) && 2 > BalFac(x)); }	



#include "curd.h"
#include "AVLinit.h"