#include<iostream>
#include<queue>
using namespace std;

int main(){
    // By default it will create a max Heap
    priority_queue<int> q;
    q.push(6);
    q.push(4);
    q.push(2);
    q.push(10);
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    cout<<q.size()<<endl;
    if(!q.empty()){
        cout<<"Not empty"<<endl;
    }


    // creating a min heap with priority queue
    priority_queue<int,vector<int>,greater<int>> minHeap;
    minHeap.push(4);
    minHeap.push(1);
    minHeap.push(16);
    minHeap.push(0);
    cout<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<minHeap.top()<<endl;


    return 0;
}