#include <iostream>
#include <string>
using namespace std;

template <typename Type>
class LList
{
private:
    int maxsize;
    int currsize;
    int curr;
    Type* listarray;

public:
    LList(int size = 100)
    {
        maxsize = size;
        currsize = curr = 0;
        listarray = new Type[maxsize];
    }
    ~LList()
    {
        delete[] listarray;
    };
    void print();
    void append(Type e);
    int size();
    void remove(int i);
    Type getvalue(int i);
};

template <typename Type>
void LList<Type>::print()
{
    for (int i = 0; i < currsize; i++)
    {
        cout << listarray[i];
        /*if (i != (currsize - 1))
            cout << ' ';*/
    }
}

template <typename Type>
void LList<Type>::append(Type e)
{
    listarray[currsize++] = e;
}

template <typename Type>
int LList<Type>::size()
{
    return currsize;
}

template<typename Type>
void LList<Type>::remove(int i) {
    int j;
    for (j = i; j < currsize-1; j++) {
        listarray[j] = listarray[j + 1];
    }
    currsize--;
}

template<typename Type>
Type LList<Type>::getvalue(int i){
    return listarray[i];
}

int main()
{
    LList<char> alist;
    string str;
    getline(cin, str);
    /*int n;
    cin >> n;*/
    for (int i = 0; i < str.size(); i++)
    {
        alist.append(str[i]);
    }
    int i=0;
    /*while(i!=alist.size())
    {*/
        for(i=0;i<alist.size();i++){
            if (alist.getvalue(i)=='x'){
                alist.remove(i);
                alist.remove(i);
                i--;
            }
        }
    //}
    
    //alist.remove('x');
    //cout << alist.size();
    alist.print();
    return 0;
}
