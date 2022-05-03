#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "AVLTree.h"
using namespace std;

template<typename T>
void print(TreeNodePtr<T> ptr)
{
	printf("%d ",ptr->data);
}
int main()
{
	vector<int> nums;
	cout << "����һ��AVL��" << endl;
	AVLTree<int> Tree;
	srand((uint32_t)time(NULL));

	for (int i = 15; i > 0 ; --i)
	{
		nums.push_back(rand() % 100);
		Tree.insert(nums.back());
	}
	printf("\n\n�������\n");
	Tree.traverse<void(TreeNodePtr<int>)>(1, print);
	printf("\n�������\n");
	Tree.traverse<void(TreeNodePtr<int>)>(2, print);
	for (int i = 0; i < 5; ++i) {
		printf("ɾ��Ԫ��: %d\n",nums[i]);
		Tree.remove(nums[i]);
	}

	printf("\n\n�������\n");
	Tree.traverse<void(TreeNodePtr<int>)>(1, print);
	printf("\n�������\n");
	Tree.traverse<void(TreeNodePtr<int>)>(2, print);

	printf("\n\nDFS ��\n");
	Tree.DFS<void(TreeNodePtr<int>)>(print);
	printf("\n\nBFS ��\n");
	Tree.BFS<void(TreeNodePtr<int>)>(print);
	printf("\nover\n");
	system("pause");
}