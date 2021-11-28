#include <iostream>
#include <string>
using namespace std;

void PreOrder(int k, string str)
{
    if (k > str.size())
        return;
    if ('A' <= str[k - 1] && str[k - 1] <= 'Z')
        cout << str[k - 1];
    PreOrder(2 * k, str);
    PreOrder(2 * k + 1, str);
}

void InOrder(int k,string str){
    if (k > str.size())
        return;
    InOrder(2*k,str);
    if ('A' <= str[k - 1] && str[k - 1] <= 'Z')
        cout << str[k - 1];
    InOrder(2*k+1,str);
}

void PostOrder(int k,string str){
    if (k > str.size())
        return;
    PostOrder(2*k,str);
    PostOrder(2*k+1,str);
    if ('A' <= str[k - 1] && str[k - 1] <= 'Z')
        cout << str[k - 1];
}

int main()
{
    string str;
    cin >> str;
    PreOrder(1, str);
    cout<<'\n';
    InOrder(1,str);
    cout<<'\n';
    PostOrder(1,str);
}