#include <TimeWhell.h>
#include <chrono>
using namespace std;

int main()
{
    YQM::timer::TimeWhell timer(YQM::timer::LEVEL1);

    YQM::timer::TimeTask t(1s,[](){printf("a");});

    timer.addtask(YQM::timer::TimeTask(1s,[](){printf("hello world!\n");}));

}