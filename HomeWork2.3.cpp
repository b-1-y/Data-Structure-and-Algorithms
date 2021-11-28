#include <iostream>

class TomQueue;
//练习编写的带头节点的链队列
class TomQueueNode
{
    friend class TomQueue;
    public:
    TomQueueNode(int input=-1, TomQueueNode* nextInput = NULL)
    {
        n = input;
        next = nextInput;
    };

    private:
    int n;
    TomQueueNode* next;
};
typedef class TomQueueNode Node;
class TomQueue
{
    private:
        TomQueueNode *head, *rear;
    public:
        TomQueue()
        {
            head = new TomQueueNode(-1,NULL);
            rear = head;
        };
        ~TomQueue();
        bool IsEmpty() {return head->next == NULL;}
        int GetFront();
        int GetRear();
        void InQueue (int input);
        void BackInQueue (int input);
        int OutQueue ();
};

int TomQueue:: GetFront()
{
    if(this->IsEmpty())
    {
        std::cout<<"Queue is Empty Fail to Read";
        exit(0);
    }
    return head->next->n;
}
int TomQueue:: GetRear()
{
    if(this->IsEmpty())
    {
        std::cout<<"Queue is Empty Fail to Read";
        exit(0);
    }
    return rear->n;
}
void TomQueue:: InQueue(int input)
{
    TomQueueNode*p = new TomQueueNode(input);
    rear->next = p;
    rear = rear->next;
}
void TomQueue:: BackInQueue(int input)
{
    TomQueueNode*p = new TomQueueNode(input,head->next);
    head->next = p;
}
int TomQueue:: OutQueue()
{
    if (this->IsEmpty())
    {
        std::cout<<"Queue Empty! Fail to Out Queue";
        exit(0);
    }
    Node* p = new Node();
    p = head->next;
    int output = p->n;
    head->next = p->next;
    delete p;
    return output;
}
TomQueue:: ~TomQueue()
{
    Node* p = new Node();
    while(head!=NULL)
    {
        p=head;
        head = head->next;
        delete p;
    }
}


void ToBuffRail(TomQueue& InRail, TomQueue(&BuffRail)[3])
{
    using namespace:: std;
    int Current;
    int EmptyRailCode=-1;
    int MaxRailCode=-1;
    if (InRail.IsEmpty()) {cout<<"Wrong Put"; return;}
    Current = InRail.OutQueue();
    int CodeOnBuffRail = -1;

    for (int i=0;i<3;i++)
    {
        if (BuffRail[i].IsEmpty())
        {
            EmptyRailCode = i;
            continue;
        }
        if (CodeOnBuffRail < BuffRail[i].GetRear() && BuffRail[i].GetRear() < Current)
        {
            MaxRailCode = i;
            CodeOnBuffRail = BuffRail[i].GetRear();
            //得到编号最大的满足条件的缓冲轨序号
        }
    }

    if (MaxRailCode != -1)
    {
        BuffRail[MaxRailCode].InQueue(Current);
        return;
    }
    if (EmptyRailCode != -1)
    {
        BuffRail[EmptyRailCode].InQueue(Current);
        return;
    }
    cout << "重排失败";
    exit(0);
}

void OutBuffRail(TomQueue& OutRail, TomQueue(&BuffRail)[3])
{
    //本函数将BuffRail三条缓冲轨中的车厢按照其编号由小到大输出到输出轨OutRail中
    int OutCarrierCode = 1000;
    int OutRailCode = -1;
    //二者分别对应最小的车厢编号与对应缓冲轨的编号
    int i = 0;
    //std::cout<<"do";

    for (i=0;i<3;i++)
    {
        if (!BuffRail[i].IsEmpty()&& OutCarrierCode > BuffRail[i].GetFront())
        {
            OutRailCode = i;
            OutCarrierCode = BuffRail[i].GetFront();
            //二者分别对应最小的车厢编号与对应缓冲轨的编号
        }
        //确定队首车厢编号最小的那一条缓冲轨
    }
    OutRail.BackInQueue(BuffRail[OutRailCode].OutQueue());
    //此命令可以等效于将编号最小的车厢输出到输出轨中。此命令之前也调用过应该没有问题...吧
    bool AllEmpty = true;
    //AllEmpty 为 true 表示此时三条缓冲轨已全部为空
    for (i=0;i<3;i++)
    {
        if (!BuffRail[i].IsEmpty())
        {
            AllEmpty = false;
        }
    }
    //遍历3条缓冲轨道，只要其中有一条不为空，AllEmpty就为false

    if (!AllEmpty)
    //只有当三条缓冲轨道不全为空的时候，才会继续递归
    {
        OutBuffRail(OutRail,BuffRail);
    }
}

TomQueue BoyangInput ()
{

    const int size = 100;
    char instring[size];
    std::cin.getline(instring,size);
    int i = 0;
    char reader;
    int input=0;

    TomQueue* InRail = new TomQueue();
    
    for (i=0;i<size;i++)
    {
        reader = instring[i];
        if (reader == ' ' || reader == '^')
        {
            continue;
        }
        else if( reader == '\0')
        {
            break;
        }
        else if('0'<=reader&&reader<='9')
        {
                input = (int)reader - 48;
                //如果监测到reader是数字，就以数字的形式输入
                InRail->BackInQueue(input);
        }
    }
    //Boyang Input @copyright Tom's Macbook Pro
    return *InRail;
}

int main()
{
    
    TomQueue InRail = BoyangInput();
    
    TomQueue OutRail;
    TomQueue BuffRail[3];
    
    while(!InRail.IsEmpty())
    {
        ToBuffRail(InRail,BuffRail);
    }
    OutBuffRail(OutRail,BuffRail);

    while(!OutRail.IsEmpty())
    {
        std::cout<<OutRail.OutQueue()<<' ';
    }
    return 0;
}