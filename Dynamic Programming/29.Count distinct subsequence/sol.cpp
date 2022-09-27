#include<iostream>
#include<string>
#include<vector>
using namespace std;
    

    // Memoization code
    int countDistinct(string s,string t,int n1,int n2,vector<vector<int>> &dp){
        if(n2<0) return 1;
        if(n1<0) return 0;
        
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        
        int count=0;
        if(s[n1]==t[n2]) count=countDistinct(s,t,n1-1,n2-1,dp);
        
        count=count+countDistinct(s,t,n1-1,n2,dp);        
        return dp[n1][n2]=count;
        
    }
    
    int numDistinct(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return countDistinct(s,t,n1-1,n2-1,dp);
    }


// Tabulation code
 int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));
       
        for(int i=0;i<=n;i++) dp[i][0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return (int)dp[n][m];
    }