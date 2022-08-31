   #include<iostream>
   #include<vector>
   using namespace std;
   
//   Leetcode

// Memoization code
int minPath(vector<vector<int>> &triangle,int n,int i,int j,vector<vector<int>> &dp){
        if(i>=n) return 0;
        if(dp[i][j]!=0) return dp[i][j];
        dp[i][j]=triangle[i][j]+min(minPath(triangle,n,i+1,j,dp),minPath(triangle,n,i+1,j+1,dp));    
        return dp[i][j];
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    return minPath(triangle,n,0,0,dp);
}



//    Tabulation with space optimization
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
       vector<int> dp(n+2,0);
       for(int i=n-1;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[j]=triangle[i][j]+min(dp[j],dp[j+1]);
            }
      }

    return dp[0];
    }
