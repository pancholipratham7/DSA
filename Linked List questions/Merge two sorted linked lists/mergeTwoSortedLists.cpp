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

//function for merging two sorted lists
Node* mergeTwoSortedLists(Node *&h1,Node* &h2){

    // we will be applying the same concept as we did in arrays

    // head for new Linked list
    Node *newHead=NULL;

    // pointer for storing the address of previous list
    Node *prev=NULL;


    while(h1!=NULL && h2!=NULL){
        Node *temp=NULL;
            if(h1->data<=h2->data){
                temp=new Node(h1->data);
                if(prev!=NULL){
                    prev->next=temp;
                }
                if(newHead==NULL){
                    newHead=temp;
                }
                prev=temp;
                h1=h1->next;
            }
            else if(h1->data>h2->data) {
                temp=new Node(h2->data);
                if(prev!=NULL){
                    prev->next=temp;
                }
                if(newHead==NULL){
                    newHead=temp;
                  }
                prev=temp;
                h2=h2->next;
            }
    }

    if(h1==NULL){
        Node *temp;
        while(h2!=NULL){
            temp=new Node(h2->data);
            prev->next=temp;
            prev=temp;
            h2=h2->next;
        }
    }
        if(h2==NULL){
        Node *temp;
        while(h1!=NULL){
            temp=new Node(h1->data);
            prev->next=temp;
            prev=temp;
            h1=h1->next;
        }
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
    Node *h1=new Node(9);
    insertNodeAtHead(h1,7);
    insertNodeAtHead(h1,5);
    insertNodeAtHead(h1,1);

    Node *h2=new Node(11);
    insertNodeAtHead(h2,3);
    insertNodeAtHead(h2,1);
    printNode(h1);
    printNode(h2);


    Node*ptr=mergeTwoSortedLists(h1,h2);
    printNode(ptr);
    return 0;

}