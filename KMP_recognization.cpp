#include <iostream>
#include <string>
using namespace std;

int* GetNext(string pat)
{
    int num = pat.size();
    int* next = new int[num];
    next[0] = -1;
    int j = 0, k = -1;
    while (j < num - 1)
    {
        if (k == -1 || (k != -1 && pat[j] == pat[k]))
        {
            j++;
            k++;
            next[j] = k;
        }
        else
            k = next[k];
    }
    return next;
}

bool KMP_Find(string pat, string main, int* next)
{
    int i = 0, j = 0;
    int m = main.size();
    int n = pat.size();
    while (i < m && j < n)
    {
        if (main[i] == pat[j])
        {
            i++;
            j++;
        }
        else if (j == 0) {
            i++;
        }
        else
            j = next[j];
    }
    if (j > pat.size() - 1)
        return true;
    else
        return false;
}

int main()
{
    string pat;
    string main = "abacababdeadcde";
    cin >> pat;
    int* next = GetNext(pat);
    //cout << pat << main;
    if (KMP_Find(pat, main, next))
        cout << "匹配成功" << endl;
    else
        cout << "匹配未成功" << endl;
    for (int i = 0; i < pat.size(); i++)
    {
        cout << next[i];
    }
    return 0;
}