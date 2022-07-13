#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>

using namespace std;

// @concept
// we will first calculate the indeegre for all vertices
// then we will push the vertices with indeegre=0 in the queue
// and then we will remove the first queue element and store it in the answer vector and reduce the indeegre of its adjacent vertices by 1
// then again we will push the element with 0 indeegre in the queue
// we will continue this process till the queue is empty


void kahnAlgo(unordered_map<int,list<int>> &adj,vector<int> &ans){
    // creating the indeegre array
    vector<int> indeegre;
    for(int i=0;i<adj.size();i++){
        for(auto v:adj[i]){
                indeegre[v]++;
        }
    }

    queue<int> temp;
    for(int v=0;v<indeegre.size();v++){
        if(indeegre[v]==0){
            temp.push(v);
        }
    }
    while(!temp.empty()){
        int el=temp.front();
        for(auto i:adj[el]){
            indeegre[i]--;
            if(indeegre[i]==0){
                temp.push(i);
            }
        }
        temp.pop();
        ans.push_back(el);
    }
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
    kahnAlgo(adj,ans);
    for(auto vertex:ans){
        cout<<vertex<<" ";
    }
  
 return 0;   
}