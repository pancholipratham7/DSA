#include<iostream>
#include<vector>
using namespace std;


// Memoization Code
int maxProfit(vector<int> &price,int n,vector<int> &dp){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];    
    int maxP=0;
    for(int i=1;i<=n;i++){
        maxP=max(maxP,price[i-1]+maxProfit(price,n-i,dp));
    }
    
    return dp[n]=maxP;
}


int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<int> dp(n+1,-1);
    return maxProfit(price,n,dp);
}


//Tabulation code without space optimization
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<int> dp(n+1,-1);    
    dp[0]=0;
    for(int i=1;i<=n;i++){
            int maxP=0;
            for(int j=1;j<=i;j++){
                maxP=max(maxP,price[j-1]+dp[i-j]);
            }
       dp[i]=maxP;
    }
    return dp[n];
}


