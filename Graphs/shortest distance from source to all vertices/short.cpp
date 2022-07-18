#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
#include<queue>
#include<vector>
#include<limits.h>
using namespace std;

// first we will be applying the kahn algo to get the topological sort
// then we will one by one remove the element from the topological sort and then update the distance array
// suppose the next element in topological sort is 3
// and suppose from 3 i can go to 4 and 5
// so i will update the distance array of 4th vertex if and only if this condition is true(dist[3]+edge(3,4)<dist[4]) and dist[3] we have already calculated previously while traversing the topological 
// and similary for 5

// this code is incorrect a little bit
// check it


void kahnAlgo(unordered_map<int,list<pair<int,int>>> &adj,vector<int> &ans,int V){
    // creating the indeegre array
     int indeegre[V]={0};
    for(int i=0;i<adj.size();i++){
        for(auto v:adj[i]){
                indeegre[v.first]++;
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
            indeegre[i.first]--;
            if(indeegre[i.first]==0){
                temp.push(i.first);
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
    unordered_map<int,list<pair<int,int>>> adj;

    // prepare adjacency list
    for(int i=0;i<e;i++){
        cout<<"Enter the edge"<<endl;
        int u,v,len;
        cin>>u>>v>>len;
        adj[u].push_back(make_pair(v,len));
    }  

    vector<int> ans;
    // first of all we will find the topological sort
    kahnAlgo(adj,ans,v);
    
    //source 
    int source;
    cout<<"Enter the source"<<endl;
    cin>>source;

    int dist[v]={INT_MAX};
    dist[source]=0;

      int srcIndex;
      //finding the index of the source
      for(int i=0;i<ans.size();i++){
        if(ans[i]==source){
          srcIndex=i;
          break;
        }
      } 
      cout<<"Src Index is = "<<srcIndex<<endl;
      for(int i=srcIndex;i<ans.size();i++){
        if(dist[ans[i]]!=INT_MAX){
          for(auto j:adj[ans[i]]){
           if(dist[j.first]>dist[ans[i]]+j.second){
            dist[j.first]=j.second+dist[ans[i]];
           }
          }
        }
      }

      // print the distance array
      for(int i=srcIndex;i<ans.size();i++){
        cout<<"Distance of "<<i<<"th vertex from source = "<<dist[ans[i]]<<endl;
      }
    
   
  return 0;
}
