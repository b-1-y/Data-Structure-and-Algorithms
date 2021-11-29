#include <iostream>
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

void insertSort(int rec[],int n,int start,int incr){
    int i,j;
    for(i=start+incr;i<n;i=i+incr){
        int it=rec[i];
        for(j=i;j>=incr;j=j-incr)
            if(it<rec[j-incr]) rec[j]=rec[j-incr];
            else break;
        if(i!=j) rec[j]=it;
    }
}

void ShellSort(int rec[],int n){
    for(int gap=3;gap>=1;gap--){
        for(int j=0;j<gap;j++) insertSort(rec,n,j,gap);
        print(rec,n);
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
    /*for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    print(a,n);*/
    ShellSort(a,n);
    return 0;
}