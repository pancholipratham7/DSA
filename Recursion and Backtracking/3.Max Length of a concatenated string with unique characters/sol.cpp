#include<iostream>
#include<vector>
using namespace std;

// #Leetcode
class Solution {
public:
    bool unique(string str){
        int freq[26]={0};
        for(int i=0;i<str.length();i++){
            if(freq[str[i]-'a']==0) freq[str[i]-'a']++;
            else return false;
        }
        return true;
    }
    
    void solve(string str,vector<string> &arr,int idx,int &maxL){
       if(!unique(str)) return;
       if(idx==arr.size()){
           if(str.length()>maxL) maxL=str.length();
           return ;
       }
       solve(str+arr[idx],arr,idx+1,maxL);
       solve(str,arr,idx+1,maxL);
    }
    
    int maxLength(vector<string>& arr) {
        int maxL=0;
        solve("",arr,0,maxL);
        return maxL;
    }
};