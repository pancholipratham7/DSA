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

int kthSmallest(Node *root,int &k,int &ans){
    if(root==NULL){
        return ans;
    }

    kthSmallest(root->left,k,ans);
    k--;
    if(k==0){
        ans=root->data;
    }
    if(ans!=-1){
        return ans;
    }
    kthSmallest(root->right,k,ans);
    
    return ans; 
}

int main(){
    Node *root=buildBST(NULL);
    int k;
    cout<<"Enter the kth value"<<endl;
    cin>>k;
    int ans=-1;
    cout<<kthSmallest(root,k,ans)<<endl;
    return 0;
}