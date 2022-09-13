#include<iostream>
using namespace std;
#include<vector>


// CodeStudio
// Memoization Code
int findLCS(string s,string t,int n1,int n2,vector<vector<int>> &dp){
    if(n1==0 || n2==0){
        if(n1==0 && n2==0) return 0;
        else if(n1==0){
            for(int i=0;i<=n2;i++){
                if(t[i]==s[n1]) return 1;
            }
            return 0;
        }
            for(int i=0;i<=n1;i++){
                if(s[i]==t[n2]) return 1;
            }
            return 0;
    }
    if(dp[n1][n2]!=-1) return dp[n1][n2];
    
    int maxL=0;
    if(s[n1]==t[n2]){
        maxL=1+findLCS(s,t,n1-1,n2-1,dp);
    }
    else{
        maxL=max(findLCS(s,t,n1-1,n2,dp),findLCS(s,t,n1,n2-1,dp));
    }
    return dp[n1][n2]=maxL;
}

int lcs(string s, string t)
{
	//Write your code here
    vector<vector<int>> dp(s.length(),vector<int>(t.length(),-1));
    int n1=s.length()-1;
    int n2=t.length()-1;
    return findLCS(s,t,n1,n2,dp);
}


// Tabulation Code

int lcs(string s, string t)
{
	//Write your code here
    vector<vector<int>> dp(s.length(),vector<int>(t.length(),0));
    int n1=s.length()-1;
    int n2=t.length()-1;
    
    for(int i=0;i<=n2;i++){
            for(int j=0;j<=i;j++){
               if(s[0]==t[j]) dp[0][i]=1;
            }
    }        
    
     for(int i=0;i<=n1;i++){
            for(int j=0;j<=i;j++){
               if(s[j]==t[0]) dp[i][0]=1;
            }
    }       
    
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            int maxL=0;
            if(s[i]==t[j]){
                maxL=1+dp[i-1][j-1];
            }
            else{
                maxL=max(dp[i-1][j],dp[i][j-1]);
            }
           dp[i][j]=maxL;
        }
    }
    return dp[n1][n2];
    
}


// Tabulation code with space optimization
int lcs(string s, string t)
{
	//Write your code here
    vector<int> dp(t.length(),0),curr(t.length(),0);
    int n1=s.length()-1;
    int n2=t.length()-1;
    
    for(int i=0;i<=n2;i++){
            for(int j=0;j<=i;j++){
               if(s[0]==t[j]) dp[i]=1;
            }
    }        
    for(int i=1;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            int maxL=0;
            if(s[i]==t[j]){
                maxL=1+dp[j-1];
            }
            else{
                maxL=max(dp[j],curr[j-1]);
            }
           curr[j]=maxL;
        }
        dp=curr;
    }
    return dp[n2];    
}