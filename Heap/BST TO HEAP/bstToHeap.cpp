#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// concept
// the structure of the heap and BST given will be same
// So firstly we can find the inorder traversal of the bst first and then start placing the elements in the heap through preorder traversal

// Node
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};


// function for building tree
Node *buildBST(Node *root){

    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;

    root=new Node(data);

    if(data==-1){
        return NULL;
    }


    cout<<"Enter the data for the left node"<<endl;
    root->left=buildBST(root->left);
    cout<<"Enter the data for the right node"<<endl;
    root->right=buildBST(root->right);

    return root;
}

void inorderTraversal(Node *root,vector<int> &temp){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left,temp);
    temp.push_back(root->data);
    inorderTraversal(root->right,temp);
}

void bstToHeap(Node*root,vector<int> &temp,int &i){
    
    if(root==NULL || i==temp.size()){
        return ;
    }

    root->data=temp[i];
    i++;
    bstToHeap(root->left,temp,i);
    bstToHeap(root->right,temp,i);
    
}
// level order traversal
void levelOrderTraversal(Node *root){
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        cout<<temp->data<<" "; 

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}


int main(){
    Node *root=buildBST(NULL);
    vector<int> temp;
    // sorting the elements and storing them in a vector
    inorderTraversal(root,temp);
    int i=0;
    bstToHeap(root,temp,i);
    levelOrderTraversal(root);
    return 0;
}

