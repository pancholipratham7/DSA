#include<iostream>
#include<list>
#include<unordered_map>
#include<limits.h>
#include<set>
using namespace std;

// shortest distance from source to all destinations using djikstra's algo
// see Luv(cp one)'s video

void djikstraAlgo(unordered_map<int,list<pair<int,int>>> adj,int dist[],int v,int src){

    // priority queue
    // using priority queue or set we can get node with minimum distance in the most opitmized way
    set<pair<int,int>> st;
    
    // Initialization
    st.insert({0,src});
    dist[src]=0;
    
    // visited array
    bool visited[v+1]={false};

    while(st.size()>0){
        auto setEl=*st.begin();
        int node=setEl.second;
        st.erase(st.begin());
        if(visited[node]) continue;
        visited[node]=true;
        for(auto child:adj[node]){
            int child_node=child.first;
            int weight=child.second;
            cout<<dist[node]<<"->"<<weight<<"->"<<dist[child_node]<<endl;
            if(dist[node]+weight<dist[child_node]){
                dist[child_node]=dist[node]+weight;
                st.insert({dist[child_node],child_node});
            }
        }
    }

       for(int i=1;i<=v;i++){
        // if(dist[v]==INT_MAX){
        //     cout<<"Distance of the source to vertex "<<i<<" is = "<<"InFinity"<<endl;
        // }
        // else{
        //     cout<<"Distance of the source to vertex "<<i<<" is = "<<dist[v]<<endl;
        // }
            cout<<"Distance of the source to vertex "<<i<<" is = "<<dist[v]<<endl;
    }

}

int main(){
    int e,v;
    cout<<"Enter the edges and vertices"<<endl;
    cin>>v>>e;

    //adjacency list 
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<e;i++){
        int u,v,len;
        // cout<<"Enter the edge with its weight"<<endl;
        cin>>u>>v>>len;
        adj[u].push_back(make_pair(v,len));
    }
    cout<<endl;

    // source
    int source;
    cout<<"Enter the source"<<endl;
    cin>>source;

    // distance array for storing the final answer
    int dist[v+1]={INT_MAX};
    for(int i=0;i<v+1;i++){
        dist[i]=INT_MAX;
    }
  
    djikstraAlgo(adj,dist,v,source);
    return 0;
}