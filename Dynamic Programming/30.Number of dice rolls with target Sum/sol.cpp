#include<iostream>
#include<vector>
using namespace std;
    
    // @Leetcode
    // Memoization code
    int findWays(int n,int k,int target,vector<vector<int>> &dp){
         if(n==0){
            if(target==0) return 1;
            return 0;
        }
        
        if(dp[n][target]!=-1) return dp[n][target];
        
        int ways=0;
        for(int i=1;i<=k;i++){
            int val=target>=i ? findWays(n-1,k,target-i,dp):0;
            ways=(ways+val)%(int)(1e9+7);
        }
        return dp[n][target]=ways;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return findWays(n,k,target,dp);
        
    }

    // Tabulation code along with space optimization
    int numRollsToTarget(int n, int k, int target) {
        vector<int> prev(target+1,0),curr(target+1,0);
        prev[0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){
                int ways=0;
                for(int x=1;x<=k;x++){
                   ways=(ways+(x<=j ? prev[j-x]:0))%(int)(1e9+7);
                }
                curr[j]=ways;
            }
            prev=curr;
        }
    
        return prev[target];
    }