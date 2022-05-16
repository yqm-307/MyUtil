#pragma once
#include <chrono>
#include <functional>
#include <ctime>

namespace YQM::timer
{
typedef uintptr_t timetask_t;
typedef std::function<void(void)> TimeOutCallBack;

using std::chrono::system_clock;
using namespace std::literals::chrono_literals;

//chrono相关 类型定义（简化）
typedef std::chrono::nanoseconds   Nanoseconds;      //纳秒
typedef std::chrono::microseconds  Microseconds;     //微秒
typedef std::chrono::milliseconds  Milliseconds;     //毫秒
typedef std::chrono::seconds       Seconds;
typedef std::chrono::minutes       Minutes;
typedef std::chrono::hours         Hours;
typedef std::chrono::duration<time_t,std::ratio<86400>> Days;
typedef std::chrono::duration<time_t,std::ratio<2629746>> Months;
typedef std::chrono::duration<time_t,std::ratio<31556952>> Years;
typedef std::chrono::time_point
            <system_clock,Nanoseconds>  Timestamp;  //时间戳




namespace clock
{

//获取当前时间戳
inline Timestamp now()
{ return system_clock::now(); }

inline Timestamp nowAfter(Nanoseconds interval)
{ return now() + interval; }

inline Timestamp nowBefore(Nanoseconds interval)
{ return now() - interval; }
inline time_t utcms(Timestamp&& ts)
{
    return ts.time_since_epoch().count()/1000/1000;
}

//月份
inline time_t day(Timestamp&& ts= now())
{
    time_t tt = system_clock::to_time_t(ts);
    tm utc_tm = *gmtime(&tt);
    return utc_tm.tm_mday;
}
inline time_t month(Timestamp&& ts=now())
{
    time_t s = utcms(std::move(ts))/1000;    //ms
    return (s%(31556952)/(2629746));
}
inline time_t hour(Timestamp&& ts=now())
{
    time_t s = utcms(std::move(ts))/1000;    //ms
    return (s%(86400))/(3600);
}
inline time_t year(Timestamp&& ts=now())
{
    time_t tt = system_clock::to_time_t(ts);
    tm utc_tm = *gmtime(&tt);
    return 1900+utc_tm.tm_year;

}

inline time_t minute(Timestamp&& ts=now())
{
    time_t tt = system_clock::to_time_t(ts);
    tm utc_tm = *gmtime(&tt);
    return utc_tm.tm_min;
}
inline time_t second(Timestamp&& ts=now())
{
    time_t tt = system_clock::to_time_t(ts);
    tm utc_tm = *gmtime(&tt);
    return utc_tm.tm_sec;
}
inline time_t millisecond(Timestamp&& ts=now())
{
    time_t ms = utcms(std::move(ts));
    return (ms%1000);
}

}

}