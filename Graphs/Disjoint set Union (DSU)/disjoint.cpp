#include<iostream>
using namespace std;

//storing parent for all elements 
int parent[100];
int size[100];

// making a separate node (disconnected component)
void makeNode(int v){
    parent[v]=v;
    size[v]=1;
}

int findParent(int v){
    if(v==parent[v]) return v;
    // optimization : Union by path compression
    return parent[v]=findParent(parent[v]);
}

void Union(int u,int v){
    int root1=findParent(u);
    int root2=findParent(v);

    // optimization
    // union by size
    // we will add the component with lesser elements to the component with higher no of elements
    if(size[root1]>=size[root2]){
        parent[root2]=root1;
        size[root1]=+size[root2];
    }
    else{
        parent[root1]=root2;
        size[root2]=+size[root1];
    }
}

int main(){
    // n-> no of nodes
    // k->no of edges (representing a union operation)
    int n,k;
    cout<<"Enter the number of nodes and edges"<<endl;
    cin>>n>>k;

    // make nodes
    for(int i=0;i<n;i++){
        makeNode(i);
    }

    for(int i=0;i<k;i++){
        int u,v;
        cout<<"Enter the edge for which you need to perform the union operation"<<endl;
        cin>>u>>v;
        Union(u,v);
    }

    // printing parent for all the nodes
    for(int i=0;i<n;i++){
        cout<<parent[n]<<" ";
    }

    return 0;
}