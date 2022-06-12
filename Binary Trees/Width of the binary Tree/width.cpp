#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// @Leetcode question Width of the binary Tree

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

int calWidth(Node *root){
    queue<pair<Node*,int>> q;
    int maxWidth=1;
    if(root->left){
    q.push(make_pair(root->left,2));

    }
    if(root->right){
    q.push(make_pair(root->right,3));
    }
    Node *a=NULL;
    q.push(make_pair(a,0));

    int minLength=-1;
    int maxLength=-1;

    // base is used for decreasing the index value so that the index value don't overflow
    int base=-1;
    while(!q.empty()){
        pair<Node*,int> temp=q.front();
        if(temp.first!=NULL){
            if(base==-1){
                base=temp.second-1;
            }
            temp.second=temp.second-base;
            if(minLength==-1){
                minLength=temp.second;
            }
            if(temp.first->left){
                q.push(make_pair(temp.first->left,2*temp.second-1));
            }
            if(temp.first->right){
                q.push(make_pair(temp.first->right,2*temp.second));
            }
            maxLength=temp.second;
        }

        if(temp.first==NULL){
            if(maxLength==-1 && minLength==-1){
                break;
            }
            if(maxWidth<(maxLength-minLength+1)){
                maxWidth=maxLength-minLength+1;
                minLength=-1;
                maxLength=-1;
            }
            Node *a=NULL;
            q.push(make_pair(a,0));
            base=-1;
        }

        q.pop();
    }
    return maxWidth;
    
}

int main(){
    Node *root=buildTree(NULL);
    cout<<calWidth(root)<<endl;
    return 0;
}