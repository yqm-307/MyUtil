#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Basic_List.hpp"
#include "DLinkList.hpp"
using namespace std;

int main()
{
	//Basic_List<int> lisf;
	DLinkList<int> list;
	
	srand((unsigned)time(NULL));
	for(int i=0;i<10;++i)
		list.push_back(rand()%10);
	
	list.traverse([](DLinkList<int>::NodeType* node){
		std::cout<<node->data<<std::endl;
	});
	
}