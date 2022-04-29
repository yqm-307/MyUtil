#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Basic_List.hpp"
#include "DLinkList.hpp"
using namespace std;

using namespace YqmUtil::Structure::List;

typedef std::function<void(DLinkList<int>::NodeType* node)> func;
func print = [](DLinkList<int>::NodeType* node){
	printf("%d ",node->data);
};
void random(DLinkList<int>& list)
{
	srand(time(NULL));
	for(int i=0;i<10;++i)
	{
		list.push_back(rand()%100);
	}
}

//template<class NodeType>
typedef int NodeType;
class DLinkList_Test
{
public:
void Main()
{
	Feature_list();
}

void Feature_list()
{
	printf("双链表测试\n");
	printf("1、打印\n");
	printf("2、首尾操作\n");
	printf("3、位置操作\n");
	printf("4、搜索\n");
	printf("输入:");
	int choice;
	cin>>choice;
	cout<<endl;

	switch (choice)
	{
	case 1:
		choice1();
		break;
	case 2:
		choice2();
		break;
	case 3:
		choice3();
		break;
	case 4:
		choice4();
		break;
	default:
		break;
	}

}


void choice1()
{
	//system("clear");
	printf("******打印******\n");
	list_.traverse(std::move(print));
	cout<<endl;
	printf("按任意键返回主界面");
	printf("pause");
	Feature_list();
}

void choice2()
{
	system("clear");
	int choice;
	printf("1、push_back\n");
	printf("2、push_front\n");
	printf("3、pop_back\n");
	printf("4、pop_front\n");
	cin>>choice;
	int rls;

	switch (choice)
	{
	case 1:
		printf("输入:");
		cin>>rls;
		list_.push_back(rls);
		break;
	case 2:
		printf("输入:");
		cin>>rls;
		list_.push_front(rls);
		break;
	case 3:
		list_.pop_back();
		break;
	case 4:
		list_.pop_front();
		break;
	default:
		break;
	}
	system("pause");
	Feature_list();
}

//删除
void choice3()
{
	printf("指定节点位置:");
	int rank;
	cin>>rank;
	printf("1、删除该节点");
	printf("2、修改该节点");
	int choice;
	cin>>choice;
	switch (choice)
	{
	case 1:{
		auto p = list_[rank];
		if(p == list_.end())
			printf("删除失败\n");
		list_.remove(p);
		}
		break;
	case 2:{
		printf("修改值:");
		int a;
		cin>>a;
		list_[rank]->data = a;
		}
		break;
	default:break;
	}
	system("pause");
	Feature_list();
}

//搜索
void choice4()
{

}
private:
	DLinkList<NodeType> list_;
};


int main()
{
	//首尾元素操作
	//DLinkList_Test test;
	//test.Main();

}