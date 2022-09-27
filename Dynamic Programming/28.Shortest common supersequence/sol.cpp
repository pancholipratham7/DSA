#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


// Leetcode
// Approach
// Concept: The lowest common subsequence characters will be common to both the strings so those characters needs to added only one time to the answer string because we want to find shortest supersequence
// All other characters other than the LCS needs to be added from both the strings to the answer string
// First fill the tabulation table using LCS algo



using namespace std;
    string shortestCommonSupersequence(string s1, string s2) {
    int n1=s1.length();
    int n2=s2.length();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
     
     string ans;      
     while(n1>0 && n2>0){
         
         if(s1[n1-1]==s2[n2-1]) {
             ans.push_back(s1[n1-1]);
             n2--;
             n1--;
         }
         
         else{
             if(dp[n1-1][n2]>dp[n1][n2-1]){
                 ans.push_back(s1[n1-1]);
                 n1--;
             }
             else{
                 ans.push_back(s2[n2-1]);
                 n2--;
             }
         }   
     }   
      
      while(n1>0) {
          ans.push_back(s1[n1-1]);
          n1--;
      }  
      
      while(n2>0){
          ans.push_back(s2[n2-1]);
          n2--;
      }
      
      reverse(ans.begin(),ans.end());
      return ans;  
    }