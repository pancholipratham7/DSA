#include<iostream>
#include<vector>
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

bool isPallindrome(Node *&head){
    Node *slow=head;
    Node *fast=head;

    // Finding the middle of the linked list
    while(slow!=NULL && fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node *mid=slow;
    Node *prev_address=NULL;

    // reversing the linked list after the middle element
    while(slow!=NULL){  
          if(prev_address!=NULL){
              slow->next=prev_address;
          }  
          prev_address=slow;
          if(slow->next==NULL){
              break;
          }
          slow=slow->next;
    }

    // pallindrome checking
    bool isPallin=true;
    while(slow!=mid){
        if(head->data==slow->data){
            head=head->next;
            slow=slow->next;
        }
        else{
            isPallin=false;
            break;
        }
    }

return isPallin;

}


int main(){
        Node *h=new Node(1);
        // This is just for adding some test elements
        insertNodeAtHead(h,2);
        insertNodeAtHead(h,3);
        insertNodeAtHead(h,2);
        insertNodeAtHead(h,1);

       if(isPallindrome(h)){
           cout<<"Yes a Pallindrome";
       } 
       else{
           cout<<"Not a Pallindrome";
       }

    return 0;
}