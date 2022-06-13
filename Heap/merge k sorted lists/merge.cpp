#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node *right;

    Node(int data){
        this->data=data;
        this->right=NULL;
    }
};

Node* mergeKSortedLists(vector<Node*> &ans){
    Node *temp=NULL;
    priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>> minHeap;
    int levels=0;
    for(int i=0;i<ans.size();i++){
        if(ans[i]==NULL){
            continue;
        }
        levels++;
        minHeap.push(make_pair(ans[i]->data,ans[i]));
    }
    if(minHeap.size()==0){
        return NULL;
    }
    temp=minHeap.top().second;
    minHeap.pop();
    if(temp->right!=NULL){
        minHeap.push(make_pair(temp->right->data,temp->right));
    }
    else{
        levels--;
    }
    Node* prev=temp;
    while(levels>0){
        Node *x=minHeap.top().second;
        prev->right=x;
        prev=x;
        minHeap.pop();
        if(x->right!=NULL){
            minHeap.push(make_pair(x->right->data,x->right));
        }
        else{
            levels--;
        }
    }
    return temp;
}

int main(){
    Node *a=new Node(1);
    Node *b=new Node(4);
    Node *c=new Node(5);
    Node *z=new Node(5);

    a->right=b;
    b->right=c;
    c->right=z;
    Node *d=new Node(1);
    Node *e=new Node(3);
    Node *f=new Node(4);
    d->right=e;
    e->right=f;
    Node *g=new Node(2);
    Node *h=new Node(6);
    g->right=h;
    vector<Node*> ans;
    ans.push_back(a);
    ans.push_back(d);
    ans.push_back(g);
    Node *l=mergeKSortedLists(ans);
    while(l!=NULL){
        cout<<l->data<<" ";
        l=l->right;
    }
    return 0;
}