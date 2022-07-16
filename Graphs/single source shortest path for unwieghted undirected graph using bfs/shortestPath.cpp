#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

// shortest path in unwieghted and undirected cyclic graphs using bfs
// we will be applying bfs and we will starting from the source vertex
// we will continue till we reach the destination
// once we reach the destination we will come out of the loop
// we need to keep a visited array inorder to track the vertex that are alreadu visited
// we also need to create a unordered_map in order to store the parent child relationship so that once we reach the destination we can trace that shortest path


void shortestPath(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited,unordered_map<int,int> &parent,int src,int dest){

    queue<int> q;
    // map for checking whether the node has been visited or not
    q.push(src);
    visited[src]=true;
    bool pathFound=false;
    while(!q.empty()){
        int x=q.front();
        for(auto i:adj[x]){
            if(!visited[i]){
                parent[i]=x;
                q.push(i);
                visited[i]=true;
                if(i==dest){
                  pathFound=true;
                    break ;
                }
            }
        }
        if(pathFound) {
          break;
        }

        q.pop();
    }

}

int main(){
    int e,v;
    cout<<"Enter the number of vertices and edges"<<endl;
    cin>>v>>e;

    // Prepare the adjacency list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
      cout<<"Enter the edge"<<endl;
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    cout<<"Enter the source and destination"<<endl;
    int s,t;
    cin>>s>>t;

    // map to keep track of the vertices already visited
    unordered_map<int,bool> visited;
    // map to store parent child relationship
    unordered_map<int,int> parent;


    shortestPath(adj,visited,parent,s,t);

    vector<int> ans;
    while(t){
        ans.push_back(t);
        t=parent[t];
    }

    // the path will be present in reverse order so we need to reverse it
    reverse(ans.begin(),ans.end());
    for(auto i:ans){
      cout<<i<<" ";
    }

    return 0;
}
