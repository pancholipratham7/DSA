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

// inserting a node in BST
Node *insertANodeInBst(Node *root,int value){
    if(root==NULL){
        root=new Node(value);
        return root;
    }

    if(root->data>value){
        root->left=insertANodeInBst(root->left,value);
    }
    if(root->data<value){
        root->right=insertANodeInBst(root->right,value);
    }

    return root;
}


int main(){
    Node *root=buildBST(NULL);
    int value;
    cout<<"Enter the value that you want to add in the BST"<<endl;
    cin>>value;
    insertANodeInBst(root,value);
    return 0;
}