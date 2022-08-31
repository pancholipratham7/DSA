  #include<iostream>
  #include<vector>
  #include<limits.h>
  using namespace std;

//   Leetcode


//   Memoization Code
  int calMinSum(vector<vector<int>> &matrix,int i,int j,vector<vector<int>> &dp){
        
        if(i>=matrix.size()) return 0;
        if(j<0 || j>=matrix[0].size()) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int val=min(calMinSum(matrix,i+1,j-1,dp),calMinSum(matrix,i+1,j,dp));
        val=min(calMinSum(matrix,i+1,j+1,dp),val);
        return dp[i][j]=(val==INT_MAX ? INT_MAX : val+matrix[i][j]);
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int minSum=INT_MAX;
        for(int i=0;i<matrix[0].size();i++){
            minSum=min(minSum,calMinSum(matrix,0,i,dp));
        }
        return minSum;
    }


// Tabulation code without space optimization
int minFallingPathSum(vector<vector<int>>& matrix) {
        int minSum=INT_MAX;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int j=0;j<matrix[0].size();j++){
            dp[m-1][j]=matrix[m-1][j];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<n;j++){
                 int val=min((j-1<0 ? INT_MAX:dp[i+1][j-1] ),dp[i+1][j]);
                 val=min((j+1>=n ? INT_MAX : dp[i+1][j+1]),val);
                 dp[i][j]=(val==INT_MAX ? INT_MAX : val+matrix[i][j]);
            }
        }
        
        for(int j=0;j<matrix[0].size();j++){
            minSum=min(minSum,dp[0][j]);
        }
        return minSum;
    }

// Tabulation code with space optimization
// optimize by yourself