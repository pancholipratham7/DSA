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
void preorder(Node *root,vector<int> &temp){
    if(root==NULL){
        return;
    }
    temp.push_back(root->data);
    preorder(root->left,temp);
    preorder(root->right,temp);
}

Node *BstFromPreorder(Node *final,vector<int> &temp,int min,int max,int &i){
        if(temp[i]<final->data && temp[i]>min){
            Node *newNode=new Node(temp[i]);
            final->left=newNode;
            i=i+1;
            BstFromPreorder(newNode,temp,min,final->data,i);
        }
        if(temp[i]>final->data && temp[i]<max){
                Node *newNode=new Node(temp[i]);
                final->right=newNode;
                i=i+1;
                BstFromPreorder(newNode,temp,final->data,max,i);
        }
}

int main(){
    Node *root=buildBST(NULL);
    vector<int> temp;
    preorder(root,temp);
    Node *final=new Node(temp[0]);
    int i=1;
    BstFromPreorder(final,temp,INT_MIN,INT_MAX,i);
    return 0;
}