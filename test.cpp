#include "src/structure/Array/stack.h"
#include "src/timer/interval.hpp"
#include <iostream>
#include <stack>
using namespace YqmUtil::Structure::Array;
using namespace YqmUtil::timer;
int main()
{
    stack<int> s;
    interval t1;
    std::cout<<"我的stack"<<std::endl;
    for(int i=0;i<10000000;++i)
    {
        s.push(i);
    }
    std::cout<<"插入耗时: "<<t1.intervalnow<ms>()<<std::endl;
    
    t1.recycle();
    while(s.size())
        s.pop();
    std::cout<<"删除耗时: "<<t1.intervalnow<ms>()<<std::endl;


    
    std::cout<<"STL stack"<<std::endl;
    std::stack<int> ss;
    t1.recycle();
    for(int i=0;i<10000000;++i)
    {
        ss.push(i);
    }
    std::cout<<"插入耗时: "<<t1.intervalnow<ms>()<<std::endl;
    
    t1.recycle();
    while(ss.size())
        ss.pop();
    std::cout<<"删除耗时: "<<t1.intervalnow<ms>()<<std::endl;
    
    
}