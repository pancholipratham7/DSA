 #include<iostream>
 using namespace std;

class Node{
    public:
        int val;
        Node *next;
    Node(int x){
        val=x;
        next=NULL;
    }
};

 Node* partition(Node* head, int x) {
        if(head==NULL){
            return head;
        }
        Node *bigNode=NULL;
        Node *bigPrev=NULL;
        Node *ans=head;
        Node *prev=NULL;
        while(head!=NULL){
            if(head->val>=x){
                if(bigNode==NULL){
                    bigNode=head;
                    bigPrev=prev;
                }
            }
            else{
                if(bigNode!=NULL && bigPrev!=NULL){
                    prev->next=head->next;
                    head->next=bigPrev->next;
                    bigPrev->next=head;
                    bigPrev=head;
                }
                else if(bigNode!=NULL && bigPrev==NULL){
                    prev->next=head->next;
                    head->next=ans;
                    ans=head;
                    bigPrev=ans;
                }
                prev=head;
            }
            prev=head;
            head=head->next;
        }
        
        return ans;
    }


 
