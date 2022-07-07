#include<vector>
#include<list>
#include<unordered_map>
#include<iostream>
using namespace std;


// this code will run for both disconnected as well as connected graphs
// there is not int main function
// this code is copied from code studio problem section : DFS traversal of graph

void dfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited,int node,vector<int> &component){
    component.push_back(node);
    visited[node]=true;
    for(auto i:adj[node]){
         if(!visited[i]){
            dfs(adj,visited,i,component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> ans;
    
//     prepare the adjacency list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
           int u=edges[i][0];
           int v=edges[i][1];
           adj[u].push_back(v);
           adj[v].push_back(u);
    }
    unordered_map<int,bool> visited;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(adj,visited,i,component);
            ans.push_back(component);
        }
    }
    return ans;
    
}

