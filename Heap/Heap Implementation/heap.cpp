#include<iostream>
using namespace std;


// array implemenation of heap
class Heap
{
    public:
    int arr[100];
    int size;

    Heap(){
        size=0;
        arr[0]=-1;
    }

    void insert(int data){
        this->size=this->size+1;
        arr[this->size]=data;
        int index=this->size;
        while(index>1){
            if(arr[index]>arr[index/2]){
                swap(arr[index],arr[index/2]);
                index=index/2;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<this->arr[i]<<" ";
        }
        cout<<endl;
    }

    void deleteElement(){
        if(size==0){
            cout<<"Nothing to delete"<<endl;
            return ;
        }
        arr[1]=arr[size];
        size=size-1;
        int i=1;
        while(i<size){
            int leftChild=2*i;
            int rightChild=2*i+1;
            if(leftChild<=size && rightChild<=size){
                if(arr[i]<arr[leftChild] || arr[i]<rightChild){
                    if(arr[leftChild]>arr[rightChild]){
                        swap(arr[leftChild],arr[i]);
                        i=leftChild;
                    }
                    else if(arr[leftChild]<arr[rightChild]){
                        swap(arr[i],arr[rightChild]);
                        i=rightChild;
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
            else if(leftChild<=size || rightChild<=size){
                if(leftChild<=size){
                    if(arr[leftChild]>arr[i]){
                        swap(arr[leftChild],arr[i]);
                        i=leftChild;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(arr[rightChild]>arr[i]){
                        swap(arr[rightChild],arr[i]);
                        i=rightChild;
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                break;
            }
           
        }
    }

};





int main(){
    Heap h;
    h.insert(80);
    h.insert(20);
    h.insert(30);
    h.insert(10);
    h.insert(5);
    h.insert(2);
    h.insert(3);
    h.print();
    h.deleteElement();
    h.print();
    return 0;
}