#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    char no;
    int num;
    Node *next;
};

class List
{
    friend class Node;

private:
    Node *head, *curr;

public:
    List()
    {
        curr = head = new Node;
        head->next = NULL;
    };
    Node *setcurr_head();
    void Insert(char no, int num);
    //void update(List L1, List L2);
    void print();
};

void List::Insert(char no, int num)
{
    Node *tmp = new Node;
    tmp->no = no;
    tmp->num = num;
    tmp->next = curr->next;
    curr->next = tmp;
    curr = tmp;
}

Node *List::setcurr_head()
{
    curr = head;
    return head;
}

void List::print()
{
    Node *p = head->next;
    while (p->next != NULL)
    {
        cout << p->no << ' ' << p->num << ",";
        p = p->next;
    }
    cout << p->no << ' ' << p->num << ";";
}

void update(List L1, List L2)
{
    Node *p, *q, *tmp;
    p = L1.setcurr_head()->next;
    q = L2.setcurr_head();
    tmp = L1.setcurr_head();
    while (q->next != NULL)
    {
        q = q->next;
        while (p->no < q->no && p->next != NULL)
        {
            tmp = p;
            p = p->next;
        }
        if (p->no > q->no)
        {
            Node *insert = new Node;
            insert->no = q->no;
            insert->num = q->num;
            tmp->next = insert;
            insert->next = p;
        }
        if (p->no == q->no)
        {
            p->num += q->num;
        }
        if (p->no < q->no)
        {
            Node *insert = new Node;
            insert->no = q->no;
            insert->num = q->num;
            p->next = insert;
            p->next->next = NULL;
        }
        p = L1.setcurr_head()->next;
    }
    return;
}

void read(List L, string str)
{
    char no = 0;
    int num = 0;
    int ctrl = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if ((('0' <= str[i] && str[i] <= '9') || ('A' <= str[i] && str[i] <= 'Z')) && ctrl == 0)
        {
            no = str[i];
            ctrl = 1;
        }
        else if ('0' <= str[i] && str[i] <= '9' && str[i] != ' ' && ctrl == 1)
        {
            num = str[i] - 48;
            ctrl = 0;
            /*while('0'<=str[++i]&&str[++i]<='9'){
                num=num*10+str[i]-48;
            }*/
        }
        if (no != 0 && num != 0)
        {
            L.Insert(no, num);
            no = 0;
            num = 0;
        }
    }
}

int main()
{
    string str_ori, str_in;
    getline(cin, str_ori);
    getline(cin, str_in);
    List Lori, Lin;
    read(Lori, str_ori);
    read(Lin, str_in);
    //Lori.print();
    //Lin.print();
    update(Lori, Lin);
    Lori.print();
}