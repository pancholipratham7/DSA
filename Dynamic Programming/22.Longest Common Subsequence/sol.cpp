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




// Tabulation code with space optimization
	//Write your code here
     int longestCommonSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<int> prev(m+1,0),curr(m+1,0);


        for(int j=0;j<=m;j++) prev[j]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[m];    
    }