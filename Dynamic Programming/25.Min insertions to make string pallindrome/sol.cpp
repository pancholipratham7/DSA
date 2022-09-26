#include<iostream>
#include<vector>
#include<string>
using namespace std;

// here there are two approaches


// Approach 1
// Memoization code 
int findMinInsertion(string str,int i,int n,vector<vector<int>> &dp){
        if(i>=n) return 0;
        if(dp[i][n]!=-1) return dp[i][n];
        if(str[i]==str[n]){
            return findMinInsertion(str,i+1,n-1,dp);
        }        
        return dp[i][n]=min(1+findMinInsertion(str,i,n-1,dp),1+findMinInsertion(str,i+1,n,dp));
}

 int minInsertions(string str) {
        int n=str.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return findMinInsertion(str,0,n-1,dp);
    }


// Tabulation Code
    int minInsertions(string str) {
        int n=str.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<n;j++){
                if(i>=j){
                    continue;
                }
                if(str[i]==str[j]){
                    dp[i][j]=dp[i+1][j-1];
                }
                else{
                    dp[i][j]=min(1+dp[i][j-1],1+dp[i+1][j]);
                }
            }
        }
    
    return dp[0][n-1];
    
    }


// Approach 2
// We will find the length of longest pallindromic subsequence
// And min insertions will be equal to =n-length of longest pallindromic subsequence
// N is length of the given string