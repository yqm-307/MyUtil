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
	cout << "构造一课AVL树" << endl;
	AVLTree<int> Tree;
	srand((uint32_t)time(NULL));

	for (int i = 15; i > 0 ; --i)
	{
		nums.push_back(rand() % 100);
		Tree.insert(nums.back());
	}
	printf("\n\n先序遍历\n");
	Tree.traverse<void(TreeNodePtr<int>)>(1, print);
	printf("\n中序遍历\n");
	Tree.traverse<void(TreeNodePtr<int>)>(2, print);
	for (int i = 0; i < 5; ++i) {
		printf("删除元素: %d\n",nums[i]);
		Tree.remove(nums[i]);
	}

	printf("\n\n先序遍历\n");
	Tree.traverse<void(TreeNodePtr<int>)>(1, print);
	printf("\n中序遍历\n");
	Tree.traverse<void(TreeNodePtr<int>)>(2, print);

	printf("\n\nDFS ：\n");
	Tree.DFS<void(TreeNodePtr<int>)>(print);
	printf("\n\nBFS ：\n");
	Tree.BFS<void(TreeNodePtr<int>)>(print);
	printf("\nover\n");
	system("pause");
}