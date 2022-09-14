  #include<iostream>
  #include<vector>
  #include<algorithm>
  using namespace std;


// This is derived from the LCS parent problem
// lEETCODE

//   Memoization code
    int findLPS(string &s1,string &s2,int m,int n,vector<vector<int>> &dp){
            
            if(m<0 || n<0) return 0;
            if(dp[m][n]!=-1) return dp[m][n];
        
            int maxLength=0;
            if(s1[m]==s2[n]){
                maxLength=1+findLPS(s1,s2,m-1,n-1,dp);
            }
            
            else{
                maxLength=max(findLPS(s1,s2,m-1,n,dp),findLPS(s1,s2,m,n-1,dp));
            }
         
            return dp[m][n]=maxLength;
    }
    
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),-1));
        return findLPS(s,s2,s.length()-1,s2.length()-1,dp);
    }