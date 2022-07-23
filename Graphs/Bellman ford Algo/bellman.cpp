#include<iostream>
#include<unordered_map>
#include<list>
#include<limits.h>
using namespace std;

// concept of bellman ford
// bellman ford is used to find shortest path from source to all other vertices
// it also words with negative weights(djikstras will not work with negative weights)
// we will relax the all the edge n-1 times (why n-1 times because on every relaxation we will get shortest distance from source to one vertex and 0 was already relaxed initially because from source to source the distance will be 0 and the left vertices are n-1 so we need to do relaxation n-1 times)
// and we will relax all the edges one more time to check the negative weight cycle
// if the dist array changes in nth relaxation then negative weight cycle exists

void bellmanFord(unordered_map<int,list<pair<int,int>>> adj,int *dist,int n){
    int v=n-1;
     for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
    }
    dist[0]=0; 
    while(v){
        for(int i=0;i<n;i++){
            for(auto el:adj[i]){
                int node=el.first;
                int wt=el.second;
                if(dist[i]+wt<dist[node]){
                    dist[node]=dist[i]+wt;
                }
            }
        }
        v--;
    }

  
 

}

int main(){
    int v,e;
    cout<<"Enter the number of vertices and edges"<<endl;
    cin>>v>>e;

    unordered_map<int,list<pair<int,int>>> adj;
    
    // creating the adjacency list
    for(int i=0;i<e;i++){
        int u,v,wt;
        // cout<<"Enter the edge with weight"<<endl;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }


    int dist[v]={0};
   
    bellmanFord(adj,dist,v);
    
     cout<<"printing dist"<<endl;
    for(int i=0;i<v;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;

}