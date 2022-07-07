#include <iostream>
#include<unordered_map>
#include<list>
#include<vector>

using namespace std;

// using dfs
// undirected graph
// @concept : 
// 1:If we go back to already visited vertex but not from the direct child

bool dfs(int node,unordered_map<int,list<int>> adj,unordered_map<int,bool> &visited,int parent){
    visited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i,adj,visited,node);
        }
        else{
            if(parent!=i){
                return true;
            }
        }
    }
    return false;
}

int main() {

    int V,E;
        cin>>V>>E;
        unordered_map<int,list<int>> adj;
        for(int i=0;i<E;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    unordered_map<int,bool> visited;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(dfs(i,adj,visited,-1)){
                cout<<"True";
                return 0;
            }
        }
    }
    cout<<"False";
	return 0;
}

