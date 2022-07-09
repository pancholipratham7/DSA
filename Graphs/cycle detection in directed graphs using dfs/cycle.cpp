#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;


bool dfs(unordered_map<int,list<int>> adj,unordered_map<int,bool> visited,int node,unordered_map<int,bool> &dfsCallVisited){

        visited[node]=true;
        dfsCallVisited[node]=true;
        for(auto i:adj[node]){
            if(dfsCallVisited[i]){
                return true;
            }
            if(!visited[i]){
                bool cycleDetected=dfs(adj,visited,i,dfsCallVisited);
                if(cycleDetected) return true;
            }
        }
        dfsCallVisited[node]=0;
        return false;
}


int main(){
    int v,e;
    cout<<"Enter the no of vertices and edges"<<endl;
    cin>>v>>e;
    unordered_map<int,list<int>> adj;
    cout<<"Enter the edges"<<endl;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u,v;
        adj[u].push_back(v);
    }

    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsCallVisited;
    bool isCycle=false;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(dfs(adj,visited,i,dfsCallVisited)){
                isCycle=true;
                break;
            }
        }
    }
    if(isCycle){
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }
    return 0;
}