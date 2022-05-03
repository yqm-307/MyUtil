#pragma once


template<typename T>
AVLTree<T>::~AVLTree()
{
	if (_size > 0)
		::destory<T>(_root);
}

template<typename T>
void destory(TreeNodePtr<T> x)
{
	if (!x) return;
	destory(x->lc); destory(x->rc);
	delete x;
}