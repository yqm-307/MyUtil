#include <iostream>
#include "Basic_Array.hpp"
#include "array.hpp"
#include "../../timer/interval.hpp"
#include <vector>

using namespace std;

using namespace YqmUtil::Structure;
using namespace YqmUtil::timer;
void testarray()
{
	Array::array<int> a;
	interval t1;
	srand((unsigned)time(NULL));

	for(int i=0;i<100000;++i)
	{
		a.push_back(rand()%1000);
	}

	cout<<"array用时  "<<t1.intervalnow<std::chrono::milliseconds>()<<endl;;

	interval t2;
	for(int i=0;i<100000;++i)
		a.push_back(rand()%1000);
	cout<<"vector用时  "<<t2.intervalnow<std::chrono::milliseconds>()<<endl;;

}
int main()
{
	testarray();
}