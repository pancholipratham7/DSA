 #include<iostream>
 using namespace std;

 //@Leetcode
class ListNode{
    public:
    int val;
    ListNode* next;   
};

 ListNode* deleteMiddle(ListNode* head) {
        int idx=0;
        ListNode *slow=head;
        ListNode *fast=head;
        ListNode *prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(prev==NULL) return NULL;
        prev->next=slow->next;
        return head;
    }