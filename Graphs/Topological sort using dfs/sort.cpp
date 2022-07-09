#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;


// Topological sort using dfs
// @concept
// think about the problem recursively
// for a node we will have mulitple choice of edges so first travel through those choices and after travelling through those choices push this node in ans vector
// because all the other vertices through those edges will lie on the right side and this node will lie on left side
// the ans vector will store the results in reverse direction

void dfs(unordered_map<int,list<int>> adj,unordered_map<int,bool> &visited,int node,vector<int> &ans){    

    visited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(adj,visited,i,ans);
        }
    }
    ans.push_back(node);
}

int main(){
    int e,v;
    cout<<"Enter number of vertices and edges"<<endl;
    cin>>v>>e;

    unordered_map<int,bool> visited;
    unordered_map<int,list<int>> adj;


    // prepare adjacency list
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

   vector<int> ans;

    cout<<endl;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(adj,visited,0,ans);
        }
    }
    cout<<endl;
    cout<<"Topological sort is="<<endl;
    cout<<ans.size()<<endl;

    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}