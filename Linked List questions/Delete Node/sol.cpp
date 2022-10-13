 #include<iostream>
 using namespace std;


//@Leetcode
class ListNode{
    public:
    int val;
    ListNode* next;   
};

 void deleteNode(ListNode* node) {
       node->val=node->next->val;
       node->next=node->next->next;
    }