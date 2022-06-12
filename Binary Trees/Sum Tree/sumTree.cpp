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
int calSum(Node *root){
    
    if(root==NULL){
        return 0;
    }

    int first=root->data;
    int second=calSum(root->left);
    int third=calSum(root->right);

    return first+second+third;
}

bool isSumTree(Node *root){
    
    if(root==NULL){
        return true;
    }
    if(root->left==NULL && root->right==NULL){
        return true;
    }

    

    int leftSum=calSum(root->left);
    cout<<"leftSum "<<leftSum<<endl;
    int rightSum=calSum(root->right);
    cout<<"rightSum "<<rightSum<<endl;
    if(leftSum+rightSum==root->data){
        return true;
    }
    return false;

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



int main(){
    Node *root=buildTree(NULL);
    inOrderTraversal(root);
    cout<<endl;
    cout<<isSumTree(root);
    return 0;
}