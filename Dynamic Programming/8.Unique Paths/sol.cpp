 #include<iostream>
 #include<vector>
 using namespace std;

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> dp(n,-1);
            if(grid[0][0]==1) return 0;
            dp[0]=1;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1) dp[j]=0;
                    else{
                            if(i==0 && j==0) continue;
                            dp[j]=(j-1<0 ? 0:dp[j-1])+(i-1<0 ? 0:dp[j]);
                    }
                }
            }
        return dp[n-1];
    }