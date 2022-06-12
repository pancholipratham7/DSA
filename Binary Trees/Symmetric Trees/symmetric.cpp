#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// @Leetcode question Symmetric Trees

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


// For symmetric trees left appears right and right appears left
// so we will do two types of traversals NLR and NRL and compare the nodes
    
    bool isSymmetric(Node* a,Node *b) {
         if(a==NULL && b==NULL){
            return true;
        }
        
        if(a==NULL || b==NULL){
            return false;
        }
                
        
        if(a->data!=b->data){
            return false;
        }
        
        bool one=isSymmetric(a->left,b->right);
        if(!one){
            return false;
        }
        bool two=isSymmetric(a->right,b->left);
        if(!two){
            return false;
        }
        return true;
    }

int main(){
    Node *root=buildTree(NULL);
    if(isSymmetric(root->left,root->right)){
        cout<<"Tree is Symmetric"<<endl;
    }
    else{
        cout<<"Tree is not symmetric"<<endl;
    }
    return 0;
}