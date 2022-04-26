#include <iostream>
#include "Vector.h"


using namespace std;
int main()
{
	Vector<int> p;

	for (int i = 10; i > 0; --i)
		p.push_back(i);


	for (int i = 0; i < p.size(); ++i)
		cout <<"第"<<i<<"个  " << p[i] << endl;
	
	for (int i = 0; i < 5; ++i)
		p.pop();
	for (int i = 0; i < p.size(); ++i)
		cout << "第" << i << "个  " << p[i] << endl;
}