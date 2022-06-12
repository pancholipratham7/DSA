#include<iostream>
#include<deque>
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

void zigZagTraversal(Node *root){
    deque<Node *> q;
    if(root==NULL){
        return ;
    }
    q.push_front(root);
    int x=2;
    string a="front";
    int y=0;
    while(!q.empty()){
       Node *temp;
       if(a=="front"){
           temp=q.front();
           cout<<temp->data<<" ";
           q.pop_front();
       }
       else if(a=="back"){
           temp=q.back();
           cout<<temp->data<<" ";
           q.pop_back();
       }

       if(a=="front"){
           q.push_back(temp->left);
           q.push_back(temp->right);
           y=y+2;
       }
        else if(a=="back"){
               q.push_front(temp->left);
               q.push_front(temp->right);
           y=y+2;
       }
       if(y==x){
           y=0;
           x=2*x;
           if(a=="front"){
               a="back";
           }
           else if(a=="back"){
               a="front";
           }
       }

    }
}




int main(){
    Node *root=buildTree(NULL);
    zigZagTraversal(root);
    return 0;
}