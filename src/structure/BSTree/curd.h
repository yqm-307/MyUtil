#pragma once

//���µ�ǰ�ڵ�ĸ߶�
template<typename T>
int AVLTree<T>::updataHeight(TreeNodePtr<T> ptr)
{
	return ptr->height = (1 + max(stature(ptr->lc), stature(ptr->rc)));
}












//�����������ȵĸ߶�
template<typename T>
void AVLTree<T>::updataHeightAnc(TreeNodePtr<T> ptr)
{
	while (ptr != nullptr) { updataHeight(ptr); ptr = ptr->parent; }
}








/*		�����ڵ㣬�Ŀ�����		*/
template<typename T>
TreeNodePtr<T> AVLTree<T>::connect34(TreeNodePtr<T> node1, TreeNodePtr<T>node2, TreeNodePtr<T>node3,
	TreeNodePtr<T>tree1, TreeNodePtr<T>tree2, TreeNodePtr<T>tree3, TreeNodePtr<T>tree4)		//ƽ���������������˳������������
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









//��ת�ӿ�
template<typename T>
TreeNodePtr<T> AVLTree<T>::rotateAt(TreeNodePtr<T> v)
{
	TreeNodePtr<T> p = v->parent;	TreeNodePtr<T> g = p->parent;	//�ҳ�connect34�е�3���ڵ�
	//�����ڵ��ϵv�����ӣ� p�Ǹ��ף� g��үү
	//����node2�����ӽڵ㻹�����ӽڵ�����ж�ʱ������������
	if (IsLChild(*p)) //p����������zig
		if (IsLChild(*v))	//v�������� ,zig
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
		if (IsRChild(*v))	//v��������  zag
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
	//���ж��Ƿ���ڱ��ڵ�
	TreeNodePtr<T>& p = search(e);	if (p!=nullptr) return p;	
	//ȷ���˽ڵ㲻���ڣ������½ڵ㣬�½ڵ�һ����Ҷ�ڵ�
	TreeNodePtr<T> x= p = new TreeNode<T>(e, _parent);
	_size++;	

	//����ѭ����ƽ��
	for (TreeNodePtr<T> i = _parent; i; i = i->parent)	//�Ӳ���ڵ�ĸ��ڵ㿪ʼ���������ƽ��
	{
		if (!AvlBalanced(*i))	//ʧ�⣬����ýӿڸ���
		{
			FromParentTo(*i) = rotateAt(tallerChild(tallerChild(i)));	//�漰�������ڵ��н����жϣ����жϼ�����ת
			break;
		}
		else
			updataHeight(i);	//ƽ��͸��¸߶ȣ��Է��߶ȴ���
	}
	return x;
}

















template<typename T>
inline TreeNodePtr<T> tallerChild(TreeNodePtr<T> x)//���ߵ�����
{
	if (stature((x)->lc) > stature((x)->rc))		//�������ߣ�����������
		return x->lc;
	else if(stature((x)->lc) < stature((x)->rc))	//�������ߣ�����������
		return x->rc;
	else  //�͸���ͬ��������
		return (x == x->parent->lc) ? (x)->lc : (x)->rc;
}












/*����Ŀ��ֵ������ʧ�ܷ���nullptr
*	���ֲ���
*/
template<typename T>
TreeNodePtr<T>& AVLTree<T>::search(const T& e)
{
	//��������������һ���ڵ�
	if (!_root || e == _root->data) {
		_parent = NULL;
		return _root;
	} //������v������
	//printf("�������ǽڵ�\n");
	for (_parent = _root; ; ) { //�����Զ�����

		TreeNodePtr<T>& c = (e < _parent->data) ? _parent->lc : _parent->rc; //ȷ������

		if (!c || e == c->data) {
			return c;
		}
		_parent = c;
	}
}










/*ɾ��������ɾ���ڵ㣬Ȼ�����ɾ���ڵ�ǰ������ƽ�⣬ƽ����Ժ�insertһ������Ҫ����removeһ���ڵ�*/
template<typename T>
bool AVLTree<T>::remove(const T& e)
{
	//���ж��Ƿ���ڱ��ڵ�
	TreeNodePtr<T>& x = search(e);	if (!x) return false;	//�ڵ㲻���ڣ����ش���
	//ȷ���˽ڵ㲻���ڣ������½ڵ㣬�½ڵ�һ����Ҷ�ڵ�
	{
		TreeNodePtr<T> w = x; //ʵ�ʱ�ժ���Ľڵ㣬��ֵͬx
		TreeNodePtr<T> succ = NULL; //ʵ�ʱ�ɾ���ڵ�Ľ�����
		if (!x->lc) //��*x��������Ϊ�գ����
			succ = x = x->rc; //ֱ�ӽ�*x�滻Ϊ��������
		else if (!x->rc) //��������Ϊ�գ����
			succ = x = x->lc; //�ԳƵش�������ע�⣺��ʱsucc != NULL
		else { //���������������ڣ���ѡ��x��ֱ�Ӻ����Ϊʵ�ʱ�ժ���ڵ㣬Ϊ����Ҫ
			w = w->succ(); //�����������У��ҵ�*x��ֱ�Ӻ��*w
			std::swap(x->data, w->data); //����*x��*w������Ԫ��
			TreeNodePtr<T> u = w->parent;
			((u == x) ? u->rc : u->lc) = succ = w->rc; //����ڵ�*w
		}
		_parent = w->parent; //��¼ʵ�ʱ�ɾ���ڵ�ĸ���
		if (succ) succ->parent = _parent; //������ɾ���ڵ�Ľ�������hot����
	}
	_size--;	//������-1

	//����ѭ����ƽ��
	for (TreeNodePtr<T> i = _parent; i; i = i->parent)	//�Ӳ���ڵ�ĸ��ڵ㿪ʼ���������ƽ��
	{
		if (!AvlBalanced(*i))	//ʧ�⣬����ýӿڸ���
			FromParentTo(*i) = rotateAt(tallerChild(tallerChild(i)));	//�漰�������ڵ��н����жϣ����жϼ�����ת
		updataHeight(i);	//ɾ�����ڵ㣬�߶ȸ����׸ı䣬��Ҫ���θ��½ڵ�
	}
	return true;
	
}
