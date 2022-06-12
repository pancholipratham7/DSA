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

// firstly finding the length of the linked list
int findLength(Node *&h){
    Node *curr=h;
    int count=0;
    while(curr!=NULL){
        count++;
        curr=curr->next;
    }
    return count;
}


// split linked list in parts
// length of linked list/K will give you no of elements you can take in one part
// If l%k==0 then we can only take l/k elements in one part
// But if it is not divisble then we can take some extra elements in part
// So we will take 1 extra in order to maintain the condition that curr and next part should have max one element diff only
void splitLinkedListInParts(Node *&h,int k,int l){
    vector<Node *> ans;
    Node *newHead=NULL;
    Node *curr=h;
    int x;
    if(l%k==0){
        x=l/k;
        l=l-(l/k);
    }
    else{
        x=(l/k)+1;
        l=l-((l/k)+1);
    }
    k=k-1;
    newHead=h;

    while(curr!=NULL){
        Node *temp=curr->next;
        if(x==1){
            ans.push_back(newHead);
            newHead=curr->next;
            curr->next=NULL;
             if(l%k==0){
                x=(l/k)+1;
                l=l-(l/k);
            }
            // this k!=0 condition we applied inorder to division by 0
        else if(k!=0){
                x=(l/k)+2;
                l=l-((l/k)+1);
            }
            k=k-1;
        }
        x--;
        curr=temp;
    }
      while(k>-1){
        Node *head=NULL;
        ans.push_back(head);
        k--;
    }
}


int main(){
        Node *h=new Node(5);
        // This is just for adding some test elements
        insertNodeAtHead(h,4);
        insertNodeAtHead(h,3);
        insertNodeAtHead(h,2);
        insertNodeAtHead(h,1);
        int k=2;
        int l=findLength(h);
        cout<<l<<endl;
        splitLinkedListInParts(h,k,l);

    return 0;
}