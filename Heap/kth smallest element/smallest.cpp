#include<iostream>
#include<queue>
using namespace std;

// concept
// make a max heap of first k elements
// and then from index=k to index<n compare every element with heap.top() and if heap.top>arr[i] then pop the element from heap and push arr[i] in heap

int main(){
    int arr[5] = {7,10,4,20,15};
    priority_queue<int> maxHeap;
    int k;
    cin>>k;
    
    for(int i=0;i<k;i++){
        maxHeap.push(arr[i]);
    }

    for(int i=k;i<5;i++){
        if(maxHeap.top()>arr[i]){
            maxHeap.pop();
            maxHeap.push(arr[i]);
      }    
    }
    cout<<maxHeap.top()<<endl;

    return 0;
}