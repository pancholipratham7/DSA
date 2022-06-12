 #include<iostream>
 using namespace std;

 
 struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

// Leetcode solution 
// We will maintain three pointers one pointer for curr node,second pointer for storing the address of last unique element
// and the third pointer for the prevNode value which will help us to compare the curr node value with previous node value

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *curr=head;
        ListNode *prev=NULL;
        int prevValue=-101;
        ListNode* newHead=NULL;
        while(curr!=NULL){
              if(prevValue==-101){
                  if(curr->next->val!=curr->val){
                      newHead=curr;
                      prev=curr;
                  }
              }  
            else if(curr->next!=NULL){
                if(curr->next->val!=curr->val && curr->val!=prevValue){
                    if(newHead==NULL){
                        newHead=curr;
                    }
                    if(prev!=NULL){
                       prev->next=curr;                        
                    }
                    prev=curr;
                }
            }
            else if(curr->next==NULL){
                if(prevValue!=curr->val){
                    if(newHead==NULL){
                        newHead=curr;
                    }
                    if(prev!=NULL){
                        prev->next=curr;                        
                    }
                    prev=curr;
                }
                else{
                    if(prev!=NULL){
                        prev->next=NULL;                        
                    }
                }
            }
                prevValue=curr->val;
            curr=curr->next;
        }
        return newHead;
    }
};