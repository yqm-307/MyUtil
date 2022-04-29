#include "interval.hpp"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <thread>

int main()
{
    using namespace YqmUtil::timer;
    interval test;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout<<test.intervalnow<std::chrono::nanoseconds>();
}