#include <stdint.h>
#include <TimeTask.h>
#include "TimeQueue.h"
#include "src/Logger/Logger.h"
#include "src/threadpool/Thread.h"
#include "src/threadpool/ThreadPool.h"

namespace YQM::timer
{

using namespace YqmUtil;
using namespace std::chrono;


class YThreadPool;


//精度要毫秒级
class TimeWhell
{
public:
    TimeWhell();
    /**
     * @brief 时钟轮转，不停滴答
     */
    void start();

    //添加定时任务
    void addtask(TimeTask&&);
    void addtask(TimeTask&);
public:
    /**
     * @brief 时钟滴答一次，会判断 槽 里是否有task，并添加到线程池处理异步事件。
     */
    void tick();
private:
    threadpool::Thread _main;
    std::mutex _mutex;
    TimeQueue _tasktable;   
};

}