#include<iostream>
#include<queue>
using namespace std;

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
Node *buildTree(Node *root){

    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;

    root=new Node(data);

    if(data==-1){
        return NULL;
    }


    cout<<"Enter the data for the left node"<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the data for the right node"<<endl;
    root->right=buildTree(root->right);

    return root;
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

// in order traversal
void inOrderTraversal(Node *root){

    if(root==NULL){
        return ;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);

}
//preorder traversal
void preOrderTraversal(Node *root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

} 

// post Order Traversal
void postOrderTraversal(Node *root){
    if(root==NULL){
        return ;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}


int main(){
    Node *root=buildTree(NULL);
    inOrderTraversal(root);
    return 0;
}