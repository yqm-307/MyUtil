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


	//遍历：1、先序；2、中序；3、后序；错误返回-1，正确返回mode
	template<typename FUNC>int traverse(int m_mode, FUNC& f);

	//本节点开始进行DFS
	template<typename FUNC>
	void DFS(FUNC& func,TreeNodePtr<T> root=nullptr);
	template<typename FUNC>
	void BFS(FUNC& func,TreeNodePtr<T> root=nullptr);


	int size();											//子树规模
	TreeNodePtr<T> succ(); //取当前节点的直接后继

	/*该节点的平衡状态*/
	int status() const { if (parent == nullptr) return -1; return (lc->height) - (rc->height); }	//该节点平衡状态

	/*比较器*/
	bool operator>(const TreeNode<T>& node) { return data > node->data; }
	bool operator==(const TreeNode<T>& node) { return data == node->data; }
	bool operator!=(const TreeNode<T>& node) { return !(*this == node); }
	bool operator<(const TreeNode<T>& node) { return !(*this > node) && (node != this); }
private:
	/*先序遍历*/
	template<typename FUNC> void preordertrave(TreeNodePtr<T>,FUNC& func);
	/*中序遍历*/
	template<typename FUNC> void inordertrave(TreeNodePtr<T>, FUNC& func);
	/*后续遍历*/
	template<typename FUNC> void postordertrave(TreeNodePtr<T>, FUNC& func);
public:
	T data;
	int height;	//树高，avl树依赖树高计算平衡因子	单个节点树高为0，则空树为-1
	TreeNodePtr<T> parent, lc, rc;
};


#define IsRoot(x) ( ! ( (x).parent ) )								//是根节点
#define IsLChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->lc ) )	//是左孩子
#define IsRChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->rc ) )	//是右孩子
#define FromParentTo( x ) /*来自父亲的引用*/ \
   ( IsRoot(x) ? _root : ( IsLChild(x) ? (x).parent->lc : (x).parent->rc ) )	//用来改变父节点对x的指向
#include "NodeADT.h"







