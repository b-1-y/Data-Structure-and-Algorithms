#include<iostream>
using namespace std;
//此文件仅适用于用例输入格式的测试，并非正式作答
int main()
{
    const int size = 100;
    char str1[size];
    char str2[size];
    char str3[size];
    char str4[size]; 
    /*char str5[size];
    char str6[size];
    char str7[size];
    char str8[size];*/
    cin.getline(str1,size);
    cin.getline(str2,size);
    cin.getline(str3,size);
    cin.getline(str4,size); 
    /*cin.getline(str5,size);
    cin.getline(str6,size);
    cin.getline(str7,size);
    cin.getline(str8,size); */
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << str4 << endl; 
    /*cout << str5 << endl;
    cout << str6 << endl;
    cout << str7 << endl;
    cout << str8 << endl; */
    return 0;
}