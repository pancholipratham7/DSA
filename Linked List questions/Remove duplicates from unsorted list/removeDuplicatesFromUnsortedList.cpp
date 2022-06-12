#include<iostream>
#include<map>
using namespace std;


class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};


// This function is just for adding elements to the node
void insertNodeAtHead(Node *&h,int data){
    Node *temp=new Node(data);
    temp->next=h;
    h=temp;
}

    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node * &head) 
    {
     // your code goes here
     Node *curr=head;
     map<int,int> m;
     Node *prev=NULL;
     while(curr!=NULL){
         if(m[curr->data]==0){
             m[curr->data]=1;
             if(prev!=NULL){
                 prev->next=curr;
             }
            prev=curr;
         }
         curr=curr->next;
     }
     prev->next=NULL;
     return head;
}

// Print Node
    void printNode(Node *&h){
    Node *temp=h;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node *h1=new Node(3);
    insertNodeAtHead(h1,2);
    insertNodeAtHead(h1,2);
    insertNodeAtHead(h1,5);
    Node *ptr=removeDuplicates(h1);
    printNode(ptr);
    return 0;
}