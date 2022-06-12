#include<iostream>
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

// Function for rotating linked list in groups of K
Node *rotateLinkedListInGroupsOfK(Node *&h,int k){


    Node *prev=NULL;
    Node *x;
    Node *newHead=NULL;
    int count=1;
    Node *curr=h;
    Node *prev_address=NULL;
    while(curr!=NULL){
        
        if(count==1){
            x=curr;
        }
        
        // Reversing
        Node *temp=curr->next;
        curr->next=prev_address;
        prev_address=curr;

        if(count==k){
            if(newHead==NULL){
                newHead=curr;
            }
             if(prev!=NULL){
                prev->next=curr;
            }
            prev=x;
            count=0;
            prev_address=NULL;
        }

        if(count!=0 && temp==NULL){
            prev->next=curr;
        }

        curr=temp;
        count++;
    }


    return newHead;
}

void printNode(Node *&h){
    Node *temp=h;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main(){
        Node *h=new Node(9);
        // This is just for adding some test elements
        insertNodeAtHead(h,8);
        insertNodeAtHead(h,7);
        insertNodeAtHead(h,6);
        insertNodeAtHead(h,5);
        insertNodeAtHead(h,4);
        insertNodeAtHead(h,3);
        insertNodeAtHead(h,2);
        insertNodeAtHead(h,1);


        Node *h1=rotateLinkedListInGroupsOfK(h,6);
        printNode(h1);

}