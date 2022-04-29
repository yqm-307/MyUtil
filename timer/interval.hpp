/**
 * @file interval.hpp
 * @author yqm-307 (979336542@qq.com)
 * @brief 时间间隔相关函数，不讲究效率，先完善功能
 * @version 0.1
 * @date 2022-04-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <thread>
#include <chrono>


namespace YqmUtil::timer
{

class interval
{

public:
    typedef std::chrono::time_point<std::chrono::system_clock,std::chrono::nanoseconds> time_ns;
    typedef std::chrono::duration<int64_t,std::nano> timeinterval;
    interval()
    {
        begin = std::chrono::system_clock::now();
    }
    ~interval() = default;

    //获取类初始化到现在为止的时间间隔

    template<typename Clock>
    clock_t intervalnow()
    {
        end = std::chrono::system_clock::now();
        timeinterval p = end - begin;
        auto a = std::chrono::duration_cast<Clock>(p);
        return a.count();
    }

private:
    time_ns begin;
    time_ns end;  
};



}