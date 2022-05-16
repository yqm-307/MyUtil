#include <stdint.h>
#include <TimeTask.h>
#include <unistd.h>
#include "TimeQueue.h"
#include "src/Logger/Logger.h"
#include "src/threadpool/Thread.h"
#include "src/threadpool/ThreadPool.h"

namespace YQM::timer
{

using namespace YqmUtil;
using namespace std::chrono;


class YThreadPool;


class TimeWhell
{
public:
    /**
     * @brief Construct a new Time Whell object
     * @param minInterval  时间轮精度 单位ms，最小1ms
     */
    TimeWhell(TICK_INTERVAL minInterval);
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
    threadpool::ThreadPool<TimeOutCallBack> _pool;
    std::mutex _mutex;
    TimeQueue _tasktable;   
    Whell _clock;
    std::atomic_bool _running;
    TICK_INTERVAL _tick;
    std::mutex _addtask;
};

}