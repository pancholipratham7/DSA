#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i){
    int leftChild=2*i;
    int rightChild=(2*i)+1;
    int index=i;
    
    // If only one child exists
    if(leftChild>n){
        return;
    }

    if(rightChild>n){
            if(arr[i]<arr[leftChild]){
                index=leftChild;
            }
    }

    // if both the child exists
    else if(leftChild<=n && rightChild<=n){
        if(arr[i]<arr[leftChild] || arr[i]<arr[rightChild]){
            if(arr[leftChild]>arr[rightChild]){
                index=leftChild;
            }
            else if(arr[leftChild]<arr[rightChild]){
                index=rightChild;
            }
        } 
    }

    if(index!=i){
        swap(arr[i],arr[index]);
        heapify(arr,n,index);
    }
}

void print(int arr[],int n){
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int arr[8]={-1,50,60,70,102,200,100,80};
    int n=7;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    print(arr,n);
    return 0;
}