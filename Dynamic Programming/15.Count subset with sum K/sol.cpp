#include<iostream>
#include<vector>
using namespace std;


// Code Studio

// Memoization code
int countWays(vector<int> &nums,int k,int n,vector<vector<int>> &dp){
    if(n==0){
       int x=(k==0 ? 1 :0);
       int y=0;
       if(nums[n]<=k) y=((k-nums[0]==0 ? 1:0));
       return x+y;
    }
    if(dp[n][k]!=-1) return dp[n][k];
    int x=countWays(nums,k,n-1,dp);
    int y=0;
    if(nums[n]<=k) y=countWays(nums,k-nums[n],n-1,dp);
    return dp[n][k]=x+y;
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    vector<vector<int>> dp(num.size(),vector<int>(tar+1,-1));
    return countWays(num,tar,num.size()-1,dp);
}


// Tabulation code without space optimization

int findWays(vector<int> &nums, int tar)
{
    // Write your code here.
    vector<vector<int>> dp(nums.size(),vector<int>(tar+1,-1));
    for(int target=0;target<=tar;target++){
       int x=(target==0 ? 1 :0);
       int y=0;
       if(nums[0]<=target) y=((target-nums[0]==0 ? 1:0));
       dp[0][target]=x+y;
    }
    
    for(int i=1;i<nums.size();i++){
        for(int target=0;target<=tar;target++){
                int x=dp[i-1][target];
                int y=0;
                if(nums[i]<=target) y=dp[i-1][target-nums[i]];
                dp[i][target]=x+y;
        }
    }
    return dp[nums.size()-1][tar]; 
}


// Tabulation code with space optimization
int findWays(vector<int> &nums, int tar)
{
    // Write your code here.
    vector<int> prev(tar+1,0),curr(tar+1,0);
    for(int target=0;target<=tar;target++){
       int x=(target==0 ? 1 :0);
       int y=0;
       if(nums[0]<=target) y=((target-nums[0]==0 ? 1:0));
       prev[target]=x+y;
    }
    
    for(int i=1;i<nums.size();i++){
        for(int target=0;target<=tar;target++){
                int x=prev[target];
                int y=0;
                if(nums[i]<=target) y=prev[target-nums[i]];
                curr[target]=x+y;
        }
        prev=curr;
    }
    return prev[tar]; 
}