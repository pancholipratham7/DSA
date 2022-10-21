#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// First push the root node in stack
// then push the right node and then the left node and so on.....

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
vector <int> preorder(Node* root)
{
  // Your code here
  vector<int> ans;
  stack<Node*> temp;
   if(root==NULL) return ans;
   temp.push(root);
   while(!temp.empty()){
       Node *x=temp.top();
       temp.pop();
       ans.push_back(x->data);
       if(x->right) temp.push(x->right);
       if(x->left) temp.push(x->left);
   }
    return ans;
}