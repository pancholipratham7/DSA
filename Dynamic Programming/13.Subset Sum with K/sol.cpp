#include<iostream>
#include<vector>
using namespace std;


// Memoization code

bool findSubset(vector<int> &arr,int n,int target,vector<vector<int>> &dp){
        if(target==0) return true;
        if(n==0) return target==arr[n];
        if(dp[n][target]!=-1) return dp[n][target];
        
        bool notPick=findSubset(arr,n-1,target,dp);
        bool pick=false;
        if(arr[n]<=target) pick=findSubset(arr,n-1,target-arr[n],dp);
        
        return dp[n][target]=pick || notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return findSubset(arr,n-1,k,dp);
}


// Tabulation without space optimization
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
       vector<vector<bool>> dp(n,vector<bool>(k+1,0));
       for(int i=0;i<n;i++) dp[i][0]=true;
       dp[0][arr[0]]=true;
       for(int i=1;i<n;i++){
           for(int target=0;target<=k;target++){
                bool notPick=dp[i-1][target];
                bool pick=false;
                if(arr[i]<=target) pick=dp[i-1][target-arr[i]];
                dp[i][target]=pick || notPick;
           }
       }
    return dp[n-1][k];
}

//Tabulation with space optimization
#include<vector>
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
       vector<bool> prev(k+1,0),curr(k+1,0);
       prev[0]=true;
       prev[arr[0]]=true;
       for(int i=1;i<n;i++){
           for(int target=0;target<=k;target++){
                bool notPick=prev[target];
                bool pick=false;
                if(arr[i]<=target) pick=prev[target-arr[i]];
                curr[target]=pick || notPick;
           }
           prev=curr;
       }
    return prev[k];
} 

