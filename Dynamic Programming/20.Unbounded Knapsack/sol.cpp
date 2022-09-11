#include<iostream>
#include<vector>
using namespace std;

// CodeStudio

// Memoization code
int maxProfit(vector<int> &profit,vector<int> weight,int n,int w,vector<vector<int>> &dp){
    if(w==0) return 0;
    if(n==0){
        if(w>=weight[0]) return (w/weight[0])*profit[0];
        return 0;
    }
    
    if(dp[n][w]!=-1) return dp[n][w];
    
    int p1=maxProfit(profit,weight,n-1,w,dp);
    int p2=0;
    if(weight[n]<=w) p2=profit[n]+maxProfit(profit,weight,n,w-weight[n],dp);
    
    return dp[n][w]=max(p1,p2);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int>(w+1,-1));    
    return maxProfit(profit,weight,n-1,w,dp);
   
}


// Tabulation without space optimization
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int>(w+1,0));    
    for(int i=0;i<n;i++){
        dp[i][0]=0;
    }
    for(int wt=0;wt<=w;wt++){
        if(wt>=weight[0]) dp[0][wt]=(wt/weight[0])*profit[0]; 
    }
    
    for(int i=1;i<n;i++){
        for(int wt=1;wt<=w;wt++){
            int p1=dp[i-1][wt];
            int p2=0;
            if(weight[i]<=wt) p2=profit[i]+dp[i][wt-weight[i]];
            dp[i][wt]=max(p1,p2);
        }
    }
    return dp[n-1][w];
}


// Tabulation with space optimization
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<int> dp(w+1,0),curr(w+1,0);    
    for(int i=0;i<n;i++){
        dp[0]=0;
    }
    for(int wt=0;wt<=w;wt++){
        if(wt>=weight[0]) dp[wt]=(wt/weight[0])*profit[0]; 
    }
    
    for(int i=1;i<n;i++){
        for(int wt=1;wt<=w;wt++){
            int p1=dp[wt];
            int p2=0;
            if(weight[i]<=wt) p2=profit[i]+curr[wt-weight[i]];
            curr[wt]=max(p1,p2);
        }
        dp=curr;
    }
    return dp[w];
}

// Tabulation method with only  one vector array space optimization
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<int> dp(w+1,0);    
    for(int i=0;i<n;i++){
        dp[0]=0;
    }
    for(int wt=0;wt<=w;wt++){
        if(wt>=weight[0]) dp[wt]=(wt/weight[0])*profit[0]; 
    }
    
    for(int i=1;i<n;i++){
        for(int wt=1;wt<=w;wt++){
            int p1=dp[wt];
            int p2=0;
            if(weight[i]<=wt) p2=profit[i]+dp[wt-weight[i]];
            dp[wt]=max(p1,p2);
        }
    }
    return dp[w];
}
