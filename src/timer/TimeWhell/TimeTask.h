#pragma once
#include <TimeCommon.h>
#include <atomic>
#include <chrono>
#include <assert.h>
#include <src/Logger/Logger.h>

namespace YQM::timer
{

typedef std::chrono::time_point
            <system_clock,Milliseconds> TimeWhellStamp;  //时间轮最小时间
typedef std::chrono::milliseconds TimeWhellMinInterval;   //时间轮最小时间间隔

enum TICK_INTERVAL
{
    LEVEL1,//10ms
    LEVEL2,//100ms
    LEVEL3,//1s
};



/**
 * @brief 月轮(30)、周轮(4)、天轮(30)、小时轮(24)、分钟轮(60)、秒轮(60)、毫秒轮(1000)
 */
struct Whell
{
    /**
     * @brief 根据chrono获取当前月份的时间轮
     * @param val 时钟滴答一次的时间间隔
     */
    Whell(TICK_INTERVAL val):_minInterval(val)
    {init();}
    Whell(){}
    void init()
    {
        _whell[1] = clock::hour();
        _whell[2] = clock::minute();
        _whell[3] = clock::second();
        _runwhellslotmaxnum = 1000/_minInterval;
        //毫秒轮看情况分 槽位
        if(_minInterval == TICK_INTERVAL::LEVEL3)
            _whell[4] == 0;
        else
            _whell[4] = clock::millisecond()/_minInterval;
    }
    void init(Timestamp ts)
    {
        
    }

    void tick()
    {
        switch (_minInterval)
        {
        case LEVEL1:
            add(10,4);
            break;
        case LEVEL2:
            add(100,4);
            break;
        case LEVEL3:
            add(1,3);
            break;        
        default:
            break;
        }
    }    
    void add(int val,int index)
    {
        switch (index)
        {
        case 1:
            if(_whell[index]+=val >= 24)
                _whell[1]=0;
            break;
        case 2:
            if(_whell[index]+=val >= 60)
                _whell[2]=0;
                add(1,1);
            break;
        case 3:
            if(_whell[index]+=val >= 60)
                _whell[3]=0;
                add(1,2);
            break;
        case 4:
            if(_whell[index]+=val >=_runwhellslotmaxnum)
                _whell[4]=0;
                add(1,3);
            break;
        default:
            return;
            break;
        }
    }
    void setTick(TICK_INTERVAL tick)
    {
        _minInterval = tick;
    }
    bool operator>(const Whell& other)
    {
        for(int i=1;i<5;++i)
            if(_whell[i]>other._whell[i])
                return true;
        else
            return false;
    }
    bool operator<(const Whell& other)
    {
        return !((*this)>other)&&!((*this)==other);
    }
    bool operator==(const Whell& other)
    {
        for(int i=1;i<5;++i)
            if(_whell[i]!=other._whell[i])
                return false;
        return true;
    }
    
    int _whell[5];
    int _runwhellslotmaxnum; //运行轮最大槽数

    TICK_INTERVAL _minInterval;
};





struct TimeTask
{
public:

    TimeTask(Timestamp ot,TimeOutCallBack&& cb,time_t i = 0)
        :_autosetms(i),
        _timeoutcb(cb),
        _is_canceled(false)
    {}
    TimeTask(const TimeTask& other)
    {
        _clock = other._clock;
        _autosetms = other._autosetms;
        _timeoutcb = other._timeoutcb;
        //_Whells = other._Whells;
    }
    TimeTask(){};
    /**
     * @brief 在第几轮触发
     * @return int 
     */
    int GetWhells(Timestamp)
    {
        
    }
    void cancel()
    {_is_canceled.store(true);}

    bool operator==(const TimeTask& obj)
    {   return this->_clock == obj._clock;}
    bool operator!=(const TimeTask& obj)
    {   return !(*this == obj);}
    bool operator>(const TimeTask& obj)
    {   return this->_clock > obj._clock;}
    bool operator<(const TimeTask& obj)
    {   return !(*this>obj)&&*this!=obj;}

    TimeTask* Get(){return this;}


    Whell _clock;   
    time_t _autosetms;  
    TimeOutCallBack _timeoutcb;
    std::atomic_bool _is_canceled;
};

}