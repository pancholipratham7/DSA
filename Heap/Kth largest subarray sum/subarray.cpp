#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int kthLargest(int Arr[],int N,int K){
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(int i=0;i<N;i++){
            int sum=0;
            for(int j=i;j<N;j++){
                sum=sum+Arr[j];
                if(minHeap.size()<K){
                    minHeap.push(sum);
                }
                else{
                    if(minHeap.top()<sum){
                        minHeap.pop();
                        minHeap.push(sum);
                    }
                }
            }
        }
        return minHeap.top();
    }

int main(){
    int arr[4]={2,6,4,1};
    cout<<kthLargest(arr,4,3)<<endl;
    return 0;
}