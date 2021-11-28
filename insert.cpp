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
    Type *listarray;

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
    void Insert(Type e, int n);
    void print();
    void append(Type e);
    int size();
};

template <typename Type>
void LList<Type>::Insert(Type e, int n)
{
    //if (n > (currsize + 1)||n <1){cout<<"ERROR! ILLEGAL POSITION!";}
    for (int i = currsize; i >= n; i--)
    {
        listarray[i] = listarray[i - 1];
    }
    listarray[n - 1] = e;
    currsize++;
}

template <typename Type>
void LList<Type>::print()
{
    for (int i = 0; i < currsize; i++)
    {
        cout << listarray[i];
        if (i != (currsize - 1))
            cout << ' ';
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

int main()
{
    LList<char> alist;
    string str;
    getline(cin, str);
    int n;
    cin >> n;
    int j = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ' && str[i] != ';')
            alist.append(str[i]);
    }
    if (alist.size() <= 2)
        cout << "x";
    else
    {
        alist.Insert('x', n);
        if (alist.size() != 1)
            alist.print();
        else
            cout << "x";
    }
    return 0;
}
