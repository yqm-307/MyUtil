#include <TimeTask.h>
#include <src/structure/List/DListNode.h>
#include <src/structure/List/Pure_Virtual_List.h>
#include <src/structure/Array/array.h>

namespace YQM::timer
{

using namespace YqmUtil::Structure::List;
using namespace YqmUtil::Structure::Array;

struct TNode:YqmUtil::Structure::List::PureListNode<TimeTask>	//以双向链表实现为例
{
public:
	TNode() {}		 //构造一个空的节点
	TNode(TimeTask a,TNode* p = nullptr,TNode* s = nullptr)
		: data(a),pred(p),succ(s) {}						//构造一个新的节点，可以不设置后继、前继，默认为空

	virtual TNode* insertAsSucc(const TimeTask& e)		//将s更改为this后继
	{
		TNode* p = new TNode(e,this,this->succ);	//新节点，头为当前节点
		this->succ->pred = p; this->succ = p;		//更改当前节点后继指向
		return p;
	}
	virtual TNode* insertAsPred(const TimeTask& e)		//将p更改为this前继
	{
		TNode* p = new TNode(e,this->pred,this);	//新建节点前继指向
		this->pred->succ = p; this->pred = p;	//更新关联前后继
		return p;
	}
    bool operator>(const TNode& rvalue)
    { return this->data > rvalue.data;}
    bool operator==(const TNode& rvalue)
    { return this->data == rvalue.data;}
    bool operator<(const TNode& rvalue)
    { return this->data < rvalue.data;}

public:
	TimeTask data;	//数据
	TNode* succ;//后继
	TNode* pred;//前驱
};

    



class TimeQueue
{
public:
    /**
     * @brief Construct a new Time Queue object
     * @param ticktime 根据精度设置table大小
     */
    TimeQueue(TICK_INTERVAL ticktime);
    ~TimeQueue();
    
    /**
     * @brief 插入一个 task ，映射到对应的槽位
     * @param task 
     */
    void addtask(TimeTask& task);
    void addtask(TimeTask&& task);
    /**
     * @brief 取消一个 定时任务
     * @param task 
     */
    void canceltask(TimeTask& task);
    std::vector<TimeOutCallBack&> GetOutTime(Whell& timeout);
protected:
    
    /**
     * @brief 根据 任务时间戳，获取映射的槽下标
     * @return 
     */
    int GetIndexByTimestamp(const Timestamp&);

    /**
     * @brief 在指定槽中，添加升序任务
     */
    void AscendingAddTask(int index, const TimeTask&&);

    /**
     * @brief 取消任务
     */
    void AscendingDeltask(TimeTask&&);

    /**
     * @brief 清除一整条链表
     */
    void clearlist(TNode* head);
private:    
    array<TNode*> _table;    //定时任务 表
    int _slots;
    int _interval;
    TICK_INTERVAL _tick;
};
}