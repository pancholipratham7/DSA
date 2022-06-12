#include<iostream>
#include<stack>
using namespace std;

// You can use recursive solution which will be better here so watch some video

int main(){
    stack<int> s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    int sizeOfStack=4;
     int midIndex;
        // code here.. 
        if(sizeOfStack%2==0){
            midIndex=(sizeOfStack/2)-1;
        }
        else{
            midIndex=sizeOfStack/2;
        }

        stack<int> temp;
        for(int i=0;i<sizeOfStack;i++){
             if(i==midIndex){
                s.pop();
                break;
            }
            else{
                temp.push(s.top());
                s.pop();
            }
          
        }

        int x=temp.size();
        for(int i=0;i<x;i++){
            s.push(temp.top());
            temp.pop();
        }
       
       x=s.size();

        for(int i=0;i<x;i++){
            cout<<s.top()<<endl;
            s.pop();
        }

    return 0;
}