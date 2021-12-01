/*#include <iostream>
#include <string>
using namespace std;

void print(int rec[],int n){
    for(int i=0;i<n;i++)
        if(i!=n-1)
            cout<<rec[i]<<' ';
        else
            cout<<rec[n-1]<<endl;
    return;
}

void merge(int a[],int b[],int s,int m,int n){
    int i=s;
    int j=m+1;
    int k=s;
    while(i<=m&&j<=n){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
            k++;
        }
        else{
            b[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=m){b[k]=a[i];i++;k++;}
    while(j<=n){b[k]=a[j];j++;k++;}
}

void MSort(int a[],int b[],int s,int t){
    int middle;
    int* c=new int[100];
    if(s==t) b[s]=a[s];
    else{
        middle=(s+t)/2;
        MSort(a,c,s,middle);
        MSort(a,c,s,middle+1);
        merge(c,b,s,middle,t);
    }
    delete[] c;
}

void MergeSort(int a[],int n){
    MSort(a,a,0,n-1);
}

int main(){
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
    MergeSort(a,n);
    print(a,n);
}*/

#include <iostream>
#include <string>
using namespace std;

void print(int rec[], int n) {
    for (int i = 0; i < n; i++)
        if (i != n - 1)
            cout << rec[i] << ' ';
        else
            cout << rec[n - 1] << endl;
    return;
}

void  Merge(int* a, int low, int mid, int high, int n)
{
    int i = low, j = mid + 1, p = 0;//对应a数组的下标
    int* r = new int[high - low + 1];//申请另一个对应大小的数组来存放排好序的数据
    
    while (i <= mid && j <= high)
    {
        r[p++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    }
    while (i <= mid)
        r[p++] = a[i++];
    while (j <= high)
        r[p++] = a[j++];
    for (p = 0, i = low; i <= high; p++, i++)
        a[i] = r[p];//最后再把有序数据存进a数组中，使得a数组对应部分数据有序
    delete[] r;
}
//自顶向下(递归实现)
void MSort(int* a, int low, int high, int n)
{
    int* a_tmp=new int[n];
    for (int i = 0; i < n; i++) {
        a_tmp[i] = a[i];
    }
    if (low < high)
    {
        int mid = (low + high) / 2;
        MSort(a, low, mid, n);
        MSort(a, mid + 1, high, n);
        Merge(a, low, mid, high, n);
        //print(a, n);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != a_tmp[i]) {
            print(a, n);
            break;
        }
    }
    delete[] a_tmp;
}
int main()
{
    int* a = new int[100];
    int n = 0;
    int tmp = 0;
    string str;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
        a[n] = 0;
        if (!(str[i] >= '0' && str[i] < 58))
            i++;
        while (str[i] >= '0' && str[i] <= '9') {
            //tmp = str[i];
            a[n] = 10 * a[n] + str[i] - '0';
            i++;
        }
        n++;
    }
    MSort(a, 0, n - 1, n);
    /*for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;*/

    return 0;
}