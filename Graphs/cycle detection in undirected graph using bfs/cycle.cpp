#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;


// this code is directly pasted from code studio problem cycle detection in undirected graphs
// using bfs

bool bfs(unordered_map<int,list<int>> adj,int node,unordered_map<int,bool> &visited){
    queue<pair<int,int>> q;
    // map for checking whether the node has been visited or not
    q.push(make_pair(node,-1));
    visited[node]=true;
    bool cycle=false;
    while(!q.empty()){
        pair<int,int> x=q.front();
        for(auto i:adj[x.first]){
            if(!visited[i]){
                q.push(make_pair(i,x.first));
                visited[i]=true;
            }
            else{
                if(x.second!=i){
                    return true;
                }
            }
        }
     
        q.pop();
    }
    return false;
}


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int,list<int>> adj;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(bfs(adj,i,visited)){
                return "Yes";
            }
        }
    }
    return "No";
}
