#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<limits.h>
using namespace std;

// Concept
// take any vertex as starting vertex and find the min edge for it (suppose for eg there are edges 1-2 and 1-3 but 1-2 is minm so select it)
// now you need to select the min weight edge from aLL edges originating from 2 and 1 (suppose the edges are 1-3,2-4,2-6 but we will selecr 2-6 because it is minm)
// now you need to select the min weight edge from aLL edges originating from 2,1 and 6
// now keep repeating the process
// one thing you need to remember : select the edge only if it is not forming a cycle

// Algo
// we will use three data structure here
// mst array for keeping track whether a particular vertex is added to the spanning tree or not
// key array for storing the min edge to a particular vertex like key[2] represents min edge to vertex 2
// parent array for storing the parent child relationship
// see striver video for further details

void primAlgo(unordered_map<int,list<pair<int,int>>> adj,int *parent,int v){
    bool mst[v]={false};
    int key[v];
    for(int i=0;i<v;i++){
        key[i]=INT_MAX;
    }
    key[0]=0;
    bool elFound=true;
    while(elFound){
        int  minNode=INT_MAX;
        int minValue=INT_MAX;
        elFound=false;
        for(int i=0;i<v;i++){
            // we need to find the vertex with minM key and it should not be a mst because it will create a cycle
            if(minValue>key[i] && !mst[i]){
                minNode=i;
                minValue=key[i];
                elFound=true;
            }
        }
        if(!elFound) break;
        // looking at the adjacent nodes of vertex with minM key
        for(auto adjEl:adj[minNode]){
           int adjNode=adjEl.first;
           int adjNodeWt=adjEl.second;
            if(key[adjNode]>adjNodeWt && !mst[adjNode]){
                key[adjNode]=adjNodeWt;
                parent[adjNode]=minNode;
            }
        }
        mst[minNode]=true;
    }
}

int main(){
     int e,v;
    cout<<"Enter number of vertices and edges"<<endl;
    cin>>v>>e;

    unordered_map<int,list<pair<int,int>>> adj;

    // prepare adjacency list
    for(int i=0;i<e;i++){
        int u,v,len;
        cin>>u>>v>>len;
        adj[u].push_back(make_pair(v,len));
        adj[v].push_back(make_pair(u,len));
    }
    int parent[v]={-1};
    primAlgo(adj,parent,v);
    
    // Printing the parent
    for(int i=0;i<v;i++){
        cout<<parent[i]<<" ";
    }

    return 0;
}