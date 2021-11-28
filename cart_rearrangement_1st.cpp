#include <iostream>
using namespace std;

template <typename Type>
class LinkQueueNode
{
public:
    LinkQueueNode(Type& e, LinkQueueNode<Type>* p = NULL) : elem(e), next(p) {};
    Type elem;
    LinkQueueNode<Type>* next;
};

template <typename Type>
class LinkQueue
{
    friend class LinkQueueNode<Type>;

public:
    LinkQueueNode<Type>* front, * rear;
    LinkQueue() : front(NULL), rear(NULL) {};
    ~LinkQueue();
    void InQueue(Type& e);
    Type OutQueue();
    bool IsEmpty() { return rear == NULL; }
    Type getfront();
    Type getrear();
};

template <typename Type>
LinkQueue<Type>::~LinkQueue()
{
    LinkQueueNode<Type>* p;
    while (front != NULL)
    {
        p = front;
        front = front->next;
        delete p;
    }
}

template <typename Type>
void LinkQueue<Type>::InQueue(Type& e)
{
    if (front == NULL)
        front = rear = new LinkQueueNode<Type>(e, NULL);
    else
        rear = rear->next = new LinkQueueNode<Type>(e, NULL);
}

template <typename Type>
Type LinkQueue<Type>::OutQueue()
{
    LinkQueueNode<Type>* p = front;
    if (!IsEmpty()) {
        Type e = p->elem;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete p;
        return e;
    }
    else return 0;
}

template <typename Type>
Type LinkQueue<Type>::getfront()
{
    if (front != NULL)
    {
        LinkQueueNode<Type>* p = front;
        Type e = p->elem;
        /*front = front->next;
    if (front == NULL)
        rear = NULL;
    delete p;*/
        return e;
    }
    else
        return 0;
}

template <typename Type>
Type LinkQueue<Type>::getrear()
{
    if (rear != NULL)
    {
        LinkQueueNode<Type>* p = rear;
        Type e = p->elem;
        /*front = front->next;
    if (front == NULL)
        rear = NULL;
    delete p;*/
        return e;
    }
    else
        exit(0);
}

bool ToBuffRail(int* a, LinkQueue<int>* BuffRail, int a_num, int BR_num)
{
    int i, j;
    for (i = 0; i < a_num; i++)
    {
        for (j = 0; j < BR_num || (j + i) < a_num; j++)
        {
            if (BuffRail[j].IsEmpty())
            {
                BuffRail[j].InQueue(a[i]);
                break;
            }
            else if (BuffRail[j].getrear() < a[i])
            {
                BuffRail[j].InQueue(a[i]);
                break;
            }
        }
        if (j == BR_num)
            break;
    }
    if (i < a_num)
        return false;
    else
        return true;
}

void ToOutRail(LinkQueue<int>* BuffRail, int a_num, int BR_num, int* b)
{
    int i, j;
    int tmp = 0;
    for (i = 0; i < a_num; i++)
    {
        tmp = 0;
        for (j = 0; j < BR_num; j++)
        {
            if (!BuffRail[j].IsEmpty() && BuffRail[j].getfront() < BuffRail[tmp].getfront())
                tmp = j;
        }
        b[a_num - i - 1] = BuffRail[tmp].OutQueue();
    }
}

int main()
{
    int a[5], b[5];
    LinkQueue<int> BuffRail[3];
    cin >> a[4] >> a[3] >> a[2] >> a[1] >> a[0];
    bool check = ToBuffRail(a, BuffRail, 5, 3);
    if (!check)
        cout << "重排失败";
    else
    {
        //cout << "5 4 3 2 1";
        ToOutRail(BuffRail, 5, 3, b);
        cout << b[0] << ' ' << b[1] << ' ' << b[2] << ' ' << b[3] << ' ' << b[4];
    }
    return 0;
}