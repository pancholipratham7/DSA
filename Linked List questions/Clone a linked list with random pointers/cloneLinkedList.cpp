#include<iostream>
using namespace std;

int main(){
    int a=3;
    a=int(&a);
    cout<<a<<endl;
    return 0;
}