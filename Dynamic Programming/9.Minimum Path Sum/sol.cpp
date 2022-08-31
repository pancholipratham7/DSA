    #include<iostream>
    #include<vector>
    #include<limits.h>
    using namespace std;


    // Leetcode
    // Tabulation with space optimization

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> dp(n,-1);
        
        dp[0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                int x=grid[i][j];
                int a=(j-1<0 ? INT_MAX:dp[j-1]);
                int b=(i-1<0 ?INT_MAX:dp[j]);
                dp[j]=min((a==INT_MAX ? a:grid[i][j]+a),(b==INT_MAX ? b:b+grid[i][j]));
            }
        }
        
        return dp[n-1];
    }

