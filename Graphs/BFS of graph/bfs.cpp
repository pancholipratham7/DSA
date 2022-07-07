#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;

// this code will work for disconnected graphs also

void bfs(unordered_map<int,list<int>> adj,int node,vector<int> &ans,unordered_map<int,bool> &visited){
    queue<int> q;
    // map for checking whether the node has been visited or not
    unordered_map<int,bool> m;
    q.push(0);
    m[0]=true;

    while(!q.empty()){
        int x=q.front();
        for(auto i:adj[x]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
        ans.push_back(q.front());
        q.pop();
    }
}

int main(){
    int v,e;
    cout<<"Enter the number of vertices"<<endl;
    cin>>v;
    cout<<"Enter the no of edges"<<endl;
    cin>>e;
    unordered_map<int,list<int>> adj;
    cout<<"Enter edges"<<endl;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans;
    unordered_map<int,bool> visited;

    // this loop is for disconnected components
    for(int i=0;i<v;i++){
        if(!visited[i]){
            bfs(adj,i,ans,visited);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}