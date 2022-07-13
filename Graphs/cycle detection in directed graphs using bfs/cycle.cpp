#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

// we can apply kahn's algo and we know that kahn's algo will only work on DAG
// so using kahn's algo we can detect whether a cycle is present or not

void kahnAlgo(unordered_map<int,list<int>> &adj,int V,int &n){
    // creating the indeegre array
     int indeegre[V]={0};
    for(int i=0;i<adj.size();i++){
        for(auto v:adj[i]){
                indeegre[v]++;
        }
    }

    queue<int> temp;
    for(int v=0;v<V;v++){
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
        n++;
    }
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

    int n=0;
    kahnAlgo(adj,v,n);
    if(n<v){
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }

    return 0;
}