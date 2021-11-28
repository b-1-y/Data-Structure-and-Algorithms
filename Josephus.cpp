#include<iostream>
using namespace std;

template <typename Type>
class CLinkNode {
public:
	Type no;
	CLinkNode <Type>* next;
	CLinkNode(CLinkNode<Type>* next = NULL) :next(next) {}
	CLinkNode(Type d, CLinkNode <Type>* next = NULL) :no(d), next(next) {}
};

//循环链表类的定义
template <typename Type>
class CList {
	friend class CLinkNode<Type>;
private:
	CLinkNode <Type>* head, * curr;
public:
	CList() {
		curr = head = new CLinkNode<Type>;
		head->next = head;
	}
	//CList(CList<Type>& L);
	//~CList();
	bool insert(Type x);
	CLinkNode<Type>* getHead();
	//bool remove();
	void Next();
	//Type getValue();
	//void Print();
	//CLinkNode<Type>* getCurr();
};

template <typename Type>
bool CList<Type>::insert(Type x) {
	CLinkNode<Type>* s = new CLinkNode<Type>;
	if (!s) {
		cout << "Fail to give a space!" << endl;
		return false;
	}
	s->no = x;
	s->next = curr->next;
	curr->next = s;
	curr = curr->next;
	return true;
}

//获取头结点
template<typename Type>
CLinkNode<Type>* CList<Type>:: getHead() {
	return head;
}

template<typename Type>
void Josephus(CList<Type>& Js,int n,int m) {
	CLinkNode<Type>* p = Js.getHead(), * pre = NULL;
	int i, j;
	int tmp;
	for (i = 0; i < n; i++) {
		for (j = 1; j < m; j++) {
			pre = p;
			p = p->next;
		}
		if (i == n - 2)
			cout << p->no << " ";
		if (i == n - 1)
			cout << p->no;
		pre->next = p->next; 
		delete p;
		p = pre->next;
	}
}


int main(){
	CList<int> clist;	
	int i, n, m = 3;
	cin >> n;
	clist.getHead()->no = 1;
	for (i = 1; i < n; i++)clist.insert(i + 1);
	Josephus(clist, n, m);
	return 0;
} 
