#include<iostream>
using namespace std;
int main(){

    return 0;
}

class List{
public:
    virtual void clear()=0;//delete all the elements
    virtual bool insert(const Elem&)=0;
}