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
// function to find the inorder successor
 Node *findSuccessor(Node *root,Node *x,Node *successor){
        if(root==NULL){
            return successor;
        }
        if(root->data>x->data){
            if(successor->data>root->data){
                successor=root;
            }
            return findSuccessor(root->left,x,successor);
        }
        if(root->data<=x->data){
            return findSuccessor(root->right,x,successor);
        }
        return successor;
    }

int main(){
    Node *root=buildBST(NULL);
    Node *x=root->left->left;
     Node *successor=new Node(INT_MAX);
    Node *ans=findSuccessor(root,x,successor);
    if(ans->data==INT_MAX){
         ans->data=-1;   
    }
    cout<<ans->data<<endl;
    
    return 0;
}