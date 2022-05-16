#include <TimeWhell.h>

using namespace YQM::timer;



TimeWhell::TimeWhell(TICK_INTERVAL tick)
    :_tasktable(tick),
    _pool(10),
    _clock(tick),
    _running(false),
    _tick(tick)
{
    _main.Start([this](){
        start();
        return threadpool::Stop;
    });
}

void TimeWhell::start()
{
    _running.store(true);
    while (_running)
    {
        usleep(_tick);
        tick();
    }
}


void TimeWhell::tick()
{
    std::vector<TimeOutCallBack&> cbs;
    {
        std::lock_guard<std::mutex> lock(_mutex);
        cbs = _tasktable.GetOutTime(_clock);
    }
    for(int i=0;i<cbs.size();++i)
    {
        _pool.AddTask(cbs[i]);
    }
}


void TimeWhell::addtask(TimeTask&& task)
{
    std::lock_guard<std::mutex> lock(_addtask);
    _tasktable.addtask(task);
}
void TimeWhell::addtask(TimeTask& task)
{
    addtask(task);
}




