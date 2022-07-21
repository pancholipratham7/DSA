#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parent[100];
int size[100];

void make(int v){
    parent[v]=v;
    size[v]=1;
}

int findParent(int v){
    if(parent[v]==v) return v;
    return parent[v]=findParent(parent[v]);
}

void Union(int a,int b){
   a=findParent(a);
   b=findParent(b);
   if(a!=b){
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b]=a;
        size[a]=size[a]+size[b];
   }
 
}


int main(){
    int n,m;
    cout<<"Enter the number of vertices and edges"<<endl;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<m;i++){
        int u,v,wt;
        // cout<<"Enter edges with weight"<<endl;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});
    }

    
    // sorting the edges
    sort(edges.begin(),edges.end());

    // initially creating all the vertex as individual components
    for(int i=1;i<=n;i++){
        make(i);
    }

    // this variable will store the cost of spanning tree
    int cost=0;

    //selecting the min edge one by one and adding it in the spanning tree
    // the edge should not form a cycle 
    for(auto &edge:edges){
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        // checking whether the edge is forming a cycle or not
        if(findParent(u)==findParent(v)) continue;
        Union(u,v);
        cout<<u<<" "<<v<<endl;
        cost=cost+wt;
    }

    cout<<"Total cost of the minimum spanning tree is="<<cost<<endl;

    return 0;
}