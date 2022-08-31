#include<iostream>
#include<vector>
using namespace std;    

// Leetcode


// Memoization Code

int countPaths(int i,int j,int m,int n,vector<vector<int>> &dp){
       
        if(i==m-1 && j==n-1) return 1;
    
        if(i>=m || j>=n) return 0;
    
        if(dp[i][j]!=-1) return dp[i][j];
    
        return dp[i][j]=countPaths(i,j+1,m,n,dp)+countPaths(i+1,j,m,n,dp); 
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return countPaths(0,0,m,n,dp);
    }

// Tabulation code without space optimization
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                dp[i][j]= (j-1<0 ? 0:dp[i][j-1])+(i-1<0 ? 0: dp[i-1][j]);
            }
        }
        return dp[m-1][n-1];
    }


//Tabulation Code with space optimization

int uniquePaths(int m, int n) {
        vector<int> dp(n,0);
        dp[0]=1;
      
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                dp[j]= (j-1<0 ? 0:dp[j-1])+(i-1<0 ? 0: dp[j]);
            }
        }
        return dp[n-1];
    }