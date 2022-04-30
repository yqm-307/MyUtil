#pragma once

//更新当前节点的高度
template<typename T>
int AVLTree<T>::updataHeight(TreeNodePtr<T> ptr)
{
	return ptr->height = (1 + max(stature(ptr->lc), stature(ptr->rc)));
}












//更新所有祖先的高度
template<typename T>
void AVLTree<T>::updataHeightAnc(TreeNodePtr<T> ptr)
{
	while (ptr != nullptr) { updataHeight(ptr); ptr = ptr->parent; }
}








/*		三个节点，四颗子树		*/
template<typename T>
TreeNodePtr<T> AVLTree<T>::connect34(TreeNodePtr<T> node1, TreeNodePtr<T>node2, TreeNodePtr<T>node3,
	TreeNodePtr<T>tree1, TreeNodePtr<T>tree2, TreeNodePtr<T>tree3, TreeNodePtr<T>tree4)		//平衡操作，根据输入顺序区分左右旋
{
	//auto parent = node1->parent;
	node1->lc = tree1; if (tree1) tree1->parent = node1;
	node1->rc = tree2; if (tree2) tree2->parent = node1;
	updataHeight(node1);
	node3->lc = tree3;	if (tree3) tree3->parent = node3;
	node3->rc = tree4;  if (tree4) tree4->parent = node3;
	updataHeight(node3);
	node2->lc = node1; node1->parent = node2;
	node2->rc = node3; node3->parent = node2;
	//node2->parent = parent;
	//_root->parent = nullptr;
	updataHeight(node2);
	return node2;
}









//旋转接口
template<typename T>
TreeNodePtr<T> AVLTree<T>::rotateAt(TreeNodePtr<T> v)
{
	TreeNodePtr<T> p = v->parent;	TreeNodePtr<T> g = p->parent;	//找出connect34中的3个节点
	//三个节点关系v是孙子， p是父亲， g是爷爷
	//根据node2是左子节点还是右子节点可以判断时左旋还是右旋
	if (IsLChild(*p)) //p是左子树，zig
		if (IsLChild(*v))	//v是左子树 ,zig
		{
			p->parent = g->parent;
			return connect34(v, p, g, v->lc, v->rc, p->rc, g->rc);
		} 
		else				//zag
		{
			v->parent = g->parent;
			return connect34(p, v, g, p->lc, v->lc, v->rc, g->rc);
		}
	else					//zag
		if (IsRChild(*v))	//v是左子树  zag
		{
			p->parent = g->parent;
			return connect34(g, p, v, g->lc,p->lc, v->lc, v->rc);
		}
		else					//zig
		{
			v->parent = g->parent;
			return connect34(g, v, p, g->lc, v->lc, v->rc, p->rc);
		}
}











template<typename T>
TreeNodePtr<T> AVLTree<T>::insert(const T& e)
{
	//先判断是否存在本节点
	TreeNodePtr<T>& p = search(e);	if (p!=nullptr) return p;	
	//确定此节点不存在，创建新节点，新节点一定是叶节点
	TreeNodePtr<T> x= p = new TreeNode<T>(e, _parent);
	_size++;	

	//向上循环重平衡
	for (TreeNodePtr<T> i = _parent; i; i = i->parent)	//从插入节点的父节点开始，向上逐层平衡
	{
		if (!AvlBalanced(*i))	//失衡，则调用接口复衡
		{
			FromParentTo(*i) = rotateAt(tallerChild(tallerChild(i)));	//涉及的三个节点中进行判断，即判断几次旋转
			break;
		}
		else
			updataHeight(i);	//平衡就更新高度，以防高度错误
	}
	return x;
}

















template<typename T>
inline TreeNodePtr<T> tallerChild(TreeNodePtr<T> x)//更高的子树
{
	if (stature((x)->lc) > stature((x)->rc))		//左子树高，返回左子树
		return x->lc;
	else if(stature((x)->lc) < stature((x)->rc))	//右子树高，返回右子树
		return x->rc;
	else  //和父亲同侧者优先
		return (x == x->parent->lc) ? (x)->lc : (x)->rc;
}












/*查找目标值，查找失败返回nullptr
*	二分查找
*/
template<typename T>
TreeNodePtr<T>& AVLTree<T>::search(const T& e)
{
	//特殊情况：插入第一个节点
	if (!_root || e == _root->data) {
		_parent = NULL;
		return _root;
	} //在树根v处命中
	//printf("树根不是节点\n");
	for (_parent = _root; ; ) { //否则，自顶而下

		TreeNodePtr<T>& c = (e < _parent->data) ? _parent->lc : _parent->rc; //确定方向

		if (!c || e == c->data) {
			return c;
		}
		_parent = c;
	}
}










/*删除就是先删除节点，然后根据删除节点前后，向上平衡，平衡策略和insert一样，主要就是remove一个节点*/
template<typename T>
bool AVLTree<T>::remove(const T& e)
{
	//先判断是否存在本节点
	TreeNodePtr<T>& x = search(e);	if (!x) return false;	//节点不存在，返回错误
	//确定此节点不存在，创建新节点，新节点一定是叶节点
	{
		TreeNodePtr<T> w = x; //实际被摘除的节点，初值同x
		TreeNodePtr<T> succ = NULL; //实际被删除节点的接替者
		if (!x->lc) //若*x的左子树为空，则可
			succ = x = x->rc; //直接将*x替换为其右子树
		else if (!x->rc) //若右子树为空，则可
			succ = x = x->lc; //对称地处理——注意：此时succ != NULL
		else { //若左右子树均存在，则选择x的直接后继作为实际被摘除节点，为此需要
			w = w->succ(); //（在右子树中）找到*x的直接后继*w
			std::swap(x->data, w->data); //交换*x和*w的数据元素
			TreeNodePtr<T> u = w->parent;
			((u == x) ? u->rc : u->lc) = succ = w->rc; //隔离节点*w
		}
		_parent = w->parent; //记录实际被删除节点的父亲
		if (succ) succ->parent = _parent; //并将被删除节点的接替者与hot相联
	}
	_size--;	//这里是-1

	//向上循环重平衡
	for (TreeNodePtr<T> i = _parent; i; i = i->parent)	//从插入节点的父节点开始，向上逐层平衡
	{
		if (!AvlBalanced(*i))	//失衡，则调用接口复衡
			FromParentTo(*i) = rotateAt(tallerChild(tallerChild(i)));	//涉及的三个节点中进行判断，即判断几次旋转
		updataHeight(i);	//删除树节点，高度更容易改变，需要依次更新节点
	}
	return true;
	
}
