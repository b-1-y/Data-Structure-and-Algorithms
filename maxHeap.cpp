#include <iostream>
#include <string>
using namespace std;

template<typename Type>
class MaxHeap{
    private:
    Type* Heap;
    int n;
    int maxsize;

    public:
    //MaxHeap();
    MaxHeap(Type* &h,int num,int max){
        Heap=h;n=num;maxsize=max;BuildHeap();
    }
    ~MaxHeap(){};
    int heapsize(){return n;}
    bool isleaf(int pos){return (2*pos+1)>heapsize()&&(2*pos+2)>heapsize();}
    int leftchild(int pos){return 2*pos+1;}
    int rightchild(int pos){return 2*pos+2;}
    int parent(int pos){
        if(pos%2) return pos/2;
        else return pos/2-1;
    }
    void BuildHeap();
    void SwiftDown(int pos);
    void Input(Type a[],int n);
    void print();
};

template<typename Type>
void MaxHeap<Type>::BuildHeap(){
    for(int i=n/2-1;i>=0;i--)
        SwiftDown(i);
}

template<typename Type>
void MaxHeap<Type>::SwiftDown(int pos){
    if(pos<0||pos>=n) return;
    Type tmp=Heap[pos];
    while(!isleaf(pos)){
        int lc=leftchild(pos);
        if((lc<n-1)&&Heap[lc]<Heap[lc+1])lc++;
        if(tmp>=Heap[lc]) break;
        Heap[pos]=Heap[lc];
        pos=lc;
    }
    Heap[pos]=tmp;
}

template<typename Type>
void MaxHeap<Type>::print(){
    for(int i=0;i<n;i++){
        if(i!=n-1) cout<<Heap[i]<<" ";
        else cout<<Heap[i];
    }
}

int main() {
    int* a=new int[100];
    int n = 0;
    int tmp = 0;
    string str;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
        a[n]=0;
        if (!(str[i] >='0' && str[i] < 58))
            i++;
        while (str[i] >= '0' && str[i] <= '9') {
            //tmp = str[i];
            a[n] = 10 * a[n] + str[i] - '0';
            i++;
        }
        n++;
    }
    /*for(int i=0;i<n;i++)
        cout<<a[i]<<' ';*/
    MaxHeap<int> heap(a,n,100);
    heap.BuildHeap();
    heap.print();
    return 0;
}
