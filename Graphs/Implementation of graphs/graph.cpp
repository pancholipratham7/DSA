#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>> adj;

    void addEdge(int u,int v,bool direction){
        // direction=0 :vertex direction u-v
        // direction=1 :vertex direction u-v and v-u also

        adj[u].push_back(v);
        if(direction){
            adj[u].push_back(v);
        }
    }

    void printAdjacencyList(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};


int main(){
    int n,m;
    
    cout<<"Enter number of nodes"<<endl;
    cin>>n;

    cout<<"Enter number of edges"<<endl;
    cin>>m;


    Graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        // creating an undirected graph
        g.addEdge(u,v,0);
    }

    g.printAdjacencyList();

    return 0;
}