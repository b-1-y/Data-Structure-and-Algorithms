#include<iostream>
#include<string>
using namespace std;

void print(int rec[],int n){
    for(int i=0;i<n;i++)
        if(i!=n-1)
            cout<<rec[i]<<' ';
        else
            cout<<rec[n-1]<<endl;
    return;
}

int Partition(int a[],int n,int low,int high)
{
    int pivot=a[low];
    int i=0;
    while(low<high){
        while(low<high&&a[high]>pivot)--high;
        a[low]=a[high];
        while(low<high&&a[low]<=pivot)++low;
        a[high]=a[low];
    }
    a[low]=pivot;
    return low;
}

void QuickSort(int a[],int n,int low,int high){
    if(low<high){
        int pivotpos=Partition(a,n,low,high);
        QuickSort(a,n,0,pivotpos-1);
        QuickSort(a,n,pivotpos+1,high);  
        
    }
    

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
    QuickSort(a,n,0,n-1);
}