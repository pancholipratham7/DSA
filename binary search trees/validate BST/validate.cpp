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

// we will find the inorder traversal and then see whether the current element is greater than the next element or not

bool validateBST(Node *root,Node * &prev){
    
    if(root==NULL){
        return true;
    }
    
    bool one=validateBST(root->left,prev);
    if(!one) return false;
    if(prev!=NULL && root->data<=prev->data){
        return false;
    } 
    prev=root;
    bool two=validateBST(root->right,prev);
    if(!two) return false;
    
    return true;

}


int main(){
    Node *root=buildBST(NULL);
    Node *prev=NULL;
    if(validateBST(root,prev)){
        cout<<"Yes it is a binary search Tree"<<endl;
    }
    else{
        cout<<"No it is not a binary tree"<<endl;
    }
    return 0;
}