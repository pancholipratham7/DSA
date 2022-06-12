#include<iostream>
#include<stack>
using namespace std;


// Function for printing stack elements
void printStackElements(stack<int> &s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

// pushing largest elemnt to the last
void pushLargestToLast(stack<int> &s,int i,int &max,int &maxIndex,int r){
        if(i==r){
            // pushing the largest element to last
            s.push(max);
            return ;    
        }
        int x=s.top();
        if(max<=x){
            max=x;
            maxIndex=i;
        }
        s.pop();
        pushLargestToLast(s,i+1,max,maxIndex,r);
        if(i!=maxIndex){
            s.push(x);
        }
}


// function or sorting the stack
void sortTheStack(stack<int> &s,int r){
    if(r==1){
        return ;
    }
    int max=s.top();
    int maxIndex=0;
    int i=0;

    // first pushing the largest element at last
    // so last element is sorted
    pushLargestToLast(s,i,max,maxIndex,r);

    // and then sorting the remaining elements
    sortTheStack(s,r-1);
}




int main(){
    stack<int> s;
    s.push(11);
    s.push(2);
    s.push(32);
    s.push(3);
    s.push(41);
    sortTheStack(s,s.size());
    printStackElements(s);
    return 0;
}