  #include<iostream>
  #include<vector>
  #include<stack>
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

  vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> inorder;
        stack<Node*> temp;
        temp.push(root);
        root=root->left;
        while(true){
            if(root){
                temp.push(root);
                root=root->left;
            }
            else{
                if(temp.empty()) break;
                Node *x=temp.top();
                temp.pop();
                inorder.push_back(x->data);
                root=x->right;
            }
        }
        return inorder;
    }