#include<iostream>
#include<string>
using namespace std;

void remove(string str,char c){
    for(int i=0;i<str.size();i++){
        if(str[i]!=c) cout<<str[i];
        else i++;
    }
}

int main() {
    string str;
    getline(cin,str);
    remove(str,'x');
	return 0;
}

