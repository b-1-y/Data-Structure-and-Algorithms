#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;

template <typename Type>
class HuffmanTreeNode
{
private:
    HuffmanTreeNode<Type> *left;
    HuffmanTreeNode<Type> *right;
    int wgt;
    Type elem;

public:
    HuffmanTreeNode()
    {
        left = right = NULL;
        wgt = 0;
    };
    HuffmanTreeNode(HuffmanTreeNode<Type> *l, HuffmanTreeNode<Type> *right, int weight, Type elem);
    ~HuffmanTreeNode();
    int weight() { return wgt; };
    Type &element() { return elem; };
    bool isleaf() { return !left && !right; };
    void setLeft(HuffmanTreeNode<Type> *b) { left = b; };
    void setright(HuffmanTreeNode<Type> *b) { right = b; };
    HuffmanTreeNode<Type> *Left() const { return left; };
    HuffmanTreeNode<Type> *Right() const { return right; };
};

template <class Type>
class HuffmanTree
{
    friend class HuffmanTreeNode<Type>;

private:
    HuffmanTreeNode<Type> *root;

public:
    HuffmanTree() { root = NULL; };
    HuffmanTree(Type elem, int weight);
    HuffmanTree(HuffmanTree<Type> *l, HuffmanTree<Type> *r, int weight);
    void DeleteTree(HuffmanTreeNode<Type> *root);
    ~HuffmanTree();
    HuffmanTreeNode<Type> *Root() { return root; };
    int weight() { return root->weight(); };
};

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

template <typename Type>
class cmp
{
public:
    bool operator()(HuffmanTree<Type> *x, HuffmanTree<Type> *y)
    {
        return x->weight() > y->weight();
    }
};

template <typename Type>
HuffmanTree<Type> *BuildHuffmanTree(Type element[], int weight[], int n)
{
    //priority_queue < HuffmanTree<Type> *, vector<HuffmanTree<Type>*>, cmp<Type>> QHTree;
    PriorQueue<HuffmanTree<Type>> QHTree;
    for (int i = 0; i < n; i++)
        QHTree.push(new HuffmanTree<Type>(element[i], weight[i]));
    while (QHTree.size()>1){
        HuffmanTree<Type> *rc=QHTree.top();
        QHTree.pop();
        HuffmanTree<Type> *lc=QHTree.top();
        QHTree.pop();
        HuffmanTree<Type>* parent = new HuffmanTree<Type>(lc,rc,lc->weight()+rc->weight());
        QHTree.push(parent);
    }
    return QHTree.top();
}

//template<typename Type>


int main()
{
    int a[8];
    char b[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    //int l[8],r[8];
    for (int i = 0; i < 8; i++)
        cin >> a[i];
    HuffmanTree<char>* root = BuildHuffmanTree(b,a,8);
    return 0;
}