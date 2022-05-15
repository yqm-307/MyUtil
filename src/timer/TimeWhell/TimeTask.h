#pragma once
#include <TimeCommon.h>
#include <atomic>
#include <chrono>

namespace YQM::timer
{

typedef std::chrono::time_point
            <system_clock,Millisecond> TimeWhellStamp;  //时间轮最小时间
typedef std::chrono::milliseconds TimeWhellMinInterval;   //时间轮最小时间间隔

class TimeTask
{
public:

    TimeTask(Timestamp ot,TimeOutCallBack& cb,Millisecond i = 0ms)
        :_timeout(ot),
        _timeoutcb(cb),
        _is_canceled(false),
        _next(nullptr),
        _prev(nullptr)
    {}
    TimeTask();

    const Timestamp& timeout() const
    { return _timeout; } 

    bool operator==(const TimeTask& obj)
    {   return this->_timeout == obj.timeout();}
    bool operator!=(const TimeTask& obj)
    {   return this->_timeout != obj.timeout();}
    bool operator>(const TimeTask& obj)
    {   return this->_timeout>obj.timeout();}
    bool operator<(const TimeTask& obj)
    {   return !(*this>obj)&&*this!=obj;}

    TimeTask* Get(){return this;}
private:
    Timestamp   _timeout;
    Timestamp   _autosettime;
    TimeOutCallBack _timeoutcb;
    TimeTask* _next;
    TimeTask* _prev;
    std::atomic_bool    _is_canceled;   //是否被取消了
};

}