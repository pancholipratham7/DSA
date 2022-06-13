#include<iostream>
#include<queue>
using namespace std;

// @Concept
// the arrays are sorted compare the first element of every sorted array and then find min and so on.....

void mergeKSortedArrays(vector<vector<int>> &a,vector<int>& ans,int k){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap;
    for(int i=0;i<k;i++){
        minHeap.push(make_pair(a[i][0],make_pair(i,0)));
    }
    int levels=k;
    while(levels>0){
        ans.push_back(minHeap.top().first);
        int x=minHeap.top().second.first;
        int y=minHeap.top().second.second;
        minHeap.pop();
        if(a[x].size()>y+1){
            minHeap.push(make_pair(a[x][y+1],make_pair(x,y+1)));
       }
       else{
        levels--;
       }
   }
 
}

int main(){
    vector<int> ans;
    vector<vector<int>> a{{1,2,3,4},{2,2,3,4},{5,5,6,6},{7,8,9,9}};
    mergeKSortedArrays(a,ans,4);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}