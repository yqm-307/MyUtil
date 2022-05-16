#include <TimeQueue.h>
#include <atomic>
using namespace YQM::timer;

int GetSlots(TICK_INTERVAL t)
{    
    int slots=0;
    switch (t)
    {
    case LEVEL1:
        slots = 100;    //table 100 轮
        break;
    case LEVEL2:
        slots = 600;    //100ms级别大多用于秒以上，这个一般也不会太多用
        break;
    case LEVEL3:
        slots = 60;     //精度低，轮询次数就会大大减少，cpu占用率最低的方法
        break;
    default:
        break;
    }
    return slots;
}

TimeQueue::TimeQueue(TICK_INTERVAL ticktime)
    :_slots(GetSlots(ticktime)),
    _table(_slots,nullptr),
    _interval(ticktime),
    _tick(ticktime)
{
}

void TimeQueue::clearlist(TNode* head)
{
    if(head == nullptr) return;
    TNode* tmp= nullptr;

    while(head!=nullptr)
    {
        tmp = head->succ;
        delete head;
        head = tmp;
    }
    
}


TimeQueue::~TimeQueue()
{
    for(int i=0;i<_table.size();++i)
        clearlist(_table[i]);
}

int TimeQueue::GetIndexByTimestamp(const Timestamp &key)
{
    uint64_t count =  key.time_since_epoch().count()%_slots;
    assert(count < _table.size());
    return count;
}

inline int Index(TICK_INTERVAL tick,Whell&task)
{
    switch (tick)
    {
    case LEVEL1:
        return task._whell[4];
        break;
    case LEVEL2:
        return task._whell[4];
        break;
    case LEVEL3:
        return task._whell[3];
        break;
    default:
        break;
    }
}

void TimeQueue::addtask(TimeTask&& task)
{
    uint64_t index = Index(_tick,task._clock);   //对应槽 index
    assert(index < _table.size());
    this->AscendingAddTask(index,std::move(task));
}

void TimeQueue::addtask(TimeTask& task)
{
    addtask(task);
}

void TimeQueue::canceltask(TimeTask& task)
{
    AscendingDeltask(std::move(task));
}

void TimeQueue::AscendingDeltask(TimeTask&& task)
{
    task.cancel();
}

void TimeQueue::AscendingAddTask(int index, const TimeTask &&task)
{
    TimeTask _task = task;
    TNode *head = _table[index];
    if (head == nullptr)
    {    
        _table[index] = new TNode(_task);
        return;
    }
    
    TNode* th = _table[index];
    TNode* prev=head;
    //根据时间升序插入
    while(true)
    {
        //插入到最后
        if(th==nullptr)
        {
            TNode* p = new TNode(_task);
            th->succ = p;
            p->pred = th;
        }

        //插入到合适位置
        if(_task < th->data || _task == th->data)
        {
            if(th == head)
            {
                TNode* p = new TNode(_task);
                th->pred = p;
                p->succ = th;
                _table[index] = p;
                return;
            }
            else
            {
                TNode* p = new TNode(_task);
                th->insertAsPred(_task);
                return;
            }
        }
        FATAL("task add error");

    }
}


std::vector<TimeOutCallBack&> TimeQueue::GetOutTime(Whell& timeout)
{
    //找到对应槽
    int index = Index(_tick,timeout);
    assert(index<_table.size());
    if(_table[index] == nullptr)
        return {};//返回空的
    
    std::vector<TimeOutCallBack&> ret;
    //遍历超时
    TNode* node = _table[index];
    while(node->data._clock > timeout)
    {
        ret.push_back(node->data._timeoutcb);
    }
    return ret;
}
