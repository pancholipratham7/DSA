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

int findMin(Node *root){
    int min=-1;
    
    while(root!=NULL){
        min=root->data;
        root=root->left;
    }
    return min;
}

int findMax(Node *root){
    int max=-1;
    
    while(root!=NULL){
        max=root->data;
        root=root->right;
    }
    return max;
}



int main(){
    Node *root=buildBST(NULL);
    cout<<findMin(root)<<endl;
    cout<<findMax(root)<<endl;
    return 0;
}