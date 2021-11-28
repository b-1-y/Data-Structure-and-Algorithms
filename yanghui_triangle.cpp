#include <iostream>
using namespace std;

template <typename Type>
class LinkQueueNode
{
    //friend class LinkQueue<Type>;

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
    Type e = p->elem;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    delete p;
    return e;
}

void YANGHUI(int n, int i)
{
    LinkQueue<int> q;
    int a = 1, b = 0;
    q.InQueue(a);
    int s = 0;
    for (int j = 2; j <= i; j++)
    {
        q.InQueue(b);
        for (int k = 1; k <= j; k++)
        {
            int t = q.OutQueue();
            s += t;
            if (j == i)
                cout << s << ' ';
            q.InQueue(s);
            s = t;
        }
        //cout << endl;
    }
}

int main()
{
    int i;
    cin >> i;
    if (i >= 100)
        cout << "队列已满";
    else if (i > 1)
    {
        YANGHUI(100, i);
    }
    else if (i == 1) {
        cout << "1";
    }
    else
        cout << "ERROR! ILLEGAL POSITION!";
}