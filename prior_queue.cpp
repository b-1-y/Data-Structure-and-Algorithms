#include <iostream>
using namespace std;

template<typename Type>
class PriorQueue {
private:
    Type* Heap;
    int n;
    int maxsize;

public:
    PriorQueue();
    PriorQueue(Type*& h, int num, int max) {
        Heap = h; n = num; maxsize = max; BuildHeap();
    }
    ~PriorQueue() {};
    int size() { return n; }
    bool isleaf(int pos) { return (2 * pos + 1) > size() && (2 * pos + 2) > size(); }
    int leftchild(int pos) { return 2 * pos + 1; }
    int rightchild(int pos) { return 2 * pos + 2; }
    int parent(int pos) {
        if (pos % 2) return pos / 2;
        else return pos / 2 - 1;
    }
    void BuildHeap();
    void SwiftDown(int pos);
    bool push(const Type& newkey);
    void print();
    Type& pop();
    Type& top();
};

template<typename Type>
bool PriorQueue<Type>::push(const Type& newkey) {
    if (n == maxsize) return false;
    int curr = n++, p = parent(curr);
    Heap[curr] = newkey;
    while (n != 0 && (Heap[p] < newkey)) {
        Type tmp = Heap[p];
        Heap[p] = Heap[curr];
        Heap[curr] = tmp;
        curr = p; p = parent(curr);
    }
}

template<typename Type>
void PriorQueue<Type>::BuildHeap() {
    for (int i = n / 2 - 1; i >= 0; i--)
        SwiftDown(i);
}

template<typename Type>
void PriorQueue<Type>::SwiftDown(int pos) {
    if (pos < 0 || pos >= n) return;
    Type tmp = Heap[pos];
    while (!isleaf(pos)) {
        int lc = leftchild(pos);
        if ((lc < n - 1) && Heap[lc] < Heap[lc + 1])lc++;
        if (tmp >= Heap[lc]) break;
        Heap[pos] = Heap[lc];
        pos = lc;
    }
    Heap[pos] = tmp;
}

template<typename Type>
Type& PriorQueue<Type>::pop() {
    if (n == 0) cout << "Removing from an empty Heap!" << endl;
    Type tmp = Heap[0];
    if (--n != 0) {
        Heap[0] = Heap[n];
        SwiftDown(0);
    }
    return tmp;
}

template<typename Type>
Type& PriorQueue<Type>::top() {
    return Heap[0];
}

template<typename Type>
void PriorQueue<Type>::print() {
    for (int i = 0; i < n; i++) {
        if (i != n - 1) cout << Heap[i] << " ";
        else cout << Heap[i];
    }
}


int main() {
    int* a = new int[100];
    for (int i = 0; i < 8; i++) {
        a[i] = i + 1;
    }
    PriorQueue<int> pq(a,8,100);
    pq.BuildHeap();
    pq.print();
    cout << endl;
    int m = pq.top();
    int n = pq.pop();
    cout << m << ' ' << n << endl;
    pq.print();
    return 0;
}