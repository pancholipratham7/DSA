 #include<iostream>
 using namespace std;

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
    int height(Node *root){
        if(root==NULL) return 0;
        return max(1+height(root->left),1+height(root->right));
    }
    
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(root==NULL) return true;
        int lh=height(root->left);
        int rh=height(root->right);
        if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right)) return true;
        return false;
    }