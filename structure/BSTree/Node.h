#include <iostream>
#include <functional>
template<typename T> struct TreeNode;

template<typename T>
using TreeNodePtr = TreeNode<T>*;
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define stature(p) ((p) ? (p)->height : -1)
template<typename T>
struct TreeNode
{
	TreeNode(T d, TreeNodePtr<T> p = nullptr, TreeNodePtr<T> l = nullptr, TreeNodePtr<T> r = nullptr)
		:data(d), parent(p), lc(l), rc(r), height(0) {};
	~TreeNode()=default;


	//������1������2������3�����򣻴��󷵻�-1����ȷ����mode
	template<typename FUNC>int traverse(int m_mode, FUNC& f);

	//���ڵ㿪ʼ����DFS
	template<typename FUNC>
	void DFS(FUNC& func,TreeNodePtr<T> root=nullptr);
	template<typename FUNC>
	void BFS(FUNC& func,TreeNodePtr<T> root=nullptr);


	int size();											//������ģ
	TreeNodePtr<T> succ(); //ȡ��ǰ�ڵ��ֱ�Ӻ��

	/*�ýڵ��ƽ��״̬*/
	int status() const { if (parent == nullptr) return -1; return (lc->height) - (rc->height); }	//�ýڵ�ƽ��״̬

	/*�Ƚ���*/
	bool operator>(const TreeNode<T>& node) { return data > node->data; }
	bool operator==(const TreeNode<T>& node) { return data == node->data; }
	bool operator!=(const TreeNode<T>& node) { return !(*this == node); }
	bool operator<(const TreeNode<T>& node) { return !(*this > node) && (node != this); }
private:
	/*�������*/
	template<typename FUNC> void preordertrave(TreeNodePtr<T>,FUNC& func);
	/*�������*/
	template<typename FUNC> void inordertrave(TreeNodePtr<T>, FUNC& func);
	/*��������*/
	template<typename FUNC> void postordertrave(TreeNodePtr<T>, FUNC& func);
public:
	T data;
	int height;	//���ߣ�avl���������߼���ƽ������	�����ڵ�����Ϊ0�������Ϊ-1
	TreeNodePtr<T> parent, lc, rc;
};


#define IsRoot(x) ( ! ( (x).parent ) )								//�Ǹ��ڵ�
#define IsLChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->lc ) )	//������
#define IsRChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->rc ) )	//���Һ���
#define FromParentTo( x ) /*���Ը��׵�����*/ \
   ( IsRoot(x) ? _root : ( IsLChild(x) ? (x).parent->lc : (x).parent->rc ) )	//�����ı丸�ڵ��x��ָ��
#include "NodeADT.h"







