#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// for concept watch tech dose videos
// and read notes

void dfs1(vector<int> adj[],int node,vector<bool> &visited,stack<int> &temp){
	    visited[node]=true;
	    for(auto i:adj[node]){
	        if(!visited[i]){
	            dfs1(adj,i,visited,temp);
	        }
	    }
	 
	       temp.push(node);
}
	
	void dfs2(vector<int> rev[],vector<bool> &visited,int node){
	    visited[node]=true;
	    for(auto i:rev[node]){
	        if(!visited[i]){
	            dfs2(rev,visited,i);
	        }
	    }
	}
	
	void reverse(vector<int> reverse[],vector<int> adj[],int v){
	    for(int i=0;i<v;i++){
	        for(auto j:adj[i]){
	            reverse[j].push_back(i);
	        }
	    }
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        
        vector<bool> visited(V,false);
        stack<int> temp;
        // pushing elements in the stack
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs1(adj,i,visited,temp);
            }
        }
        
        // reversing the edges
        vector<int> rev[V];

        // taking out the transpose of the graph
        reverse(rev,adj,V);
        
        // marking all the elements in the visited array as false
        for(int i=0;i<V;i++){
            visited[i]=false;    
        }
        
        int component=0;
        

        while(!temp.empty()){
            int front=temp.top();
            temp.pop();
            if(!visited[front]){
                dfs2(rev,visited,front);
                component++;
            }
          
        }
        return component;
        
    }

int main(){
    int e,v;
    
    cout<<"Enter the number of edges and vertices"<<endl;
    cin>>v>>e;

    vector<int> adj[v];
    for(int i=0;i<e;i++){
        cout<<"Enter the edge"<<endl;
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    cout<<"Total number of components = "<<kosaraju(v,adj);

    return 0;
}