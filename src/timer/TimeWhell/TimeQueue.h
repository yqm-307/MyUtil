#include <TimeTask.h>
#include <src/structure/List/DListNode.h>
#include <src/structure/List/Pure_Virtual_List.h>
#include <src/structure/Array/array.h>

namespace YQM::timer
{

using namespace YqmUtil::Structure::List;
using namespace YqmUtil::Structure::Array;

class TNode:public DListNode<TimeTask>
{
public:
    bool operator>(const TNode& rvalue)
    { return this->data > rvalue.data;}
    bool operator==(const TNode& rvalue)
    { return this->data == rvalue.data;}
    bool operator<(const TNode& rvalue)
    { return this->data < rvalue.data;}
};



class TimeQueue
{
public:
    TimeQueue();
    ~TimeQueue();
    
    /**
     * @brief 插入一个 task ，映射到对应的槽位
     * @param task 
     */
    void addtask(TimeTask& task);
    void addtask(TimeTask&& task);

protected:
    /**
     * @brief Get the List By Timestamp object
     * 
     * @return TNode* 
     */
    TNode* GetListByTimestamp(const Timestamp&);

private:    
    array<TimeTask*> _table;    //定时任务 表
    
};
}