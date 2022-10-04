#include<iostream>
using namespace std;

// @lEETCODE

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

bool findSum(TreeNode *root,int targetSum,int sum){
        if(root==NULL) return false;
        if(root->right==NULL && root->left==NULL){
            if(sum+root->val==targetSum) return true;
            return false;
        }
        
        if(findSum(root->left,targetSum,sum+root->val)) return true;
        if(findSum(root->right,targetSum,sum+root->val)) return true;
        return false;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
       return findSum(root,targetSum,0);
    }