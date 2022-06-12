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

    Node* searchInBST(Node* root, int val) {
        
        if(root==NULL){
            return NULL;
        }
        
        if(root->data==val){
            return root;
        }
        
        if(root->data>val){
            return searchInBST(root->left,val);
        }
        if(root->data<val){
            return searchInBST(root->right,val);
        }
        
        return NULL;
    }

int main(){
    Node *root=buildBST(NULL);
    int value;
    cout<<"Enter the value that you want to search"<<endl;
    cin>>value;
    Node *root=searchInBST(root,value);
    return 0;
}