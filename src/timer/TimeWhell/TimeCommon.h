#pragma once
#include <chrono>
#include <functional>

namespace YQM::timer
{
typedef uintptr_t timetask_t;
typedef std::function<void(void)> TimeOutCallBack;

using std::chrono::system_clock;
using namespace std::literals::chrono_literals;

//chrono相关 类型定义（简化）
typedef std::chrono::nanoseconds   Nanosecond;      //纳秒
typedef std::chrono::microseconds  Microsecond;     //微秒
typedef std::chrono::milliseconds  Millisecond;     //毫秒
typedef std::chrono::seconds       Second;
typedef std::chrono::minutes       Minute;
typedef std::chrono::hours         Hour;
typedef std::chrono::time_point
            <system_clock,Nanosecond>  Timestamp;  //时间戳




namespace clock
{

//获取当前时间戳
inline Timestamp now()
{ return system_clock::now(); }

inline Timestamp nowAfter(Nanosecond interval)
{ return now() + interval; }

inline Timestamp nowBefore(Nanosecond interval)
{ return now() - interval; }

}

}