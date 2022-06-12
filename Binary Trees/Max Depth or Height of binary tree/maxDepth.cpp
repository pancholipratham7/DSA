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

int maxDepth(Node *root){
    if(root==NULL){
        return 0;
    }

    int h1=maxDepth(root->left);
    int h2=maxDepth(root->right);

    return max(h1,h2)+1;

}


int main(){
    Node *root=buildTree(NULL);
    cout<<maxDepth(root)<<endl;

    return 0;
}