#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans(k);
        priority_queue<pair<int,string>> pq;
        unordered_map<string,int> freq;
        for(int i=0;i<words.size();i++){
            freq[words[i]]++;
        }
        for(auto p:freq){
            pq.push({-p.second,p.first});
            if(pq.size()>k) pq.pop();
        }
        
        for(int i=k-1;i>=0;i--){
            ans[i]=pq.top().second;
            pq.pop();
        }
        return ans;
        
    }