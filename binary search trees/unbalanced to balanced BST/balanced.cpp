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

void inorderTraversal(Node *root,vector<int>& temp){
    if(root==NULL){
        return ;
    }
    inorderTraversal(root->left,temp);
    temp.push_back(root->data);
    inorderTraversal(root->right,temp);
}

Node * balancedBST(vector<int> &temp,int l,int r){
    if(l>r){
        return NULL;
    }
    int mid=(l+r)/2;
    Node *newNode=new Node(temp[mid]);
    newNode->left=balancedBST(temp,l,mid-1);
    newNode->right=balancedBST(temp,mid+1,r);
    return newNode;

}

int main(){
    Node *root=buildBST(NULL);
    vector<int> temp;
    inorderTraversal(root,temp);
    Node *ans=balancedBST(temp,0,temp.size()-1);
    return 0;
}