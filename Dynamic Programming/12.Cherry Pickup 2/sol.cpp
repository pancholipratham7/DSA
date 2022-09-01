#include<iostream>
#include<vector>
using namespace std;

// Leetcode

// Memoization Code
 int maxCherry(vector<vector<int>> &grid,int row,int c1,int c2,vector<vector<vector<int>>> &dp){
       if(row>=grid.size()) return 0;
       if(c1<0 || c2<0 || c1>=grid[0].size() || c2>=grid[0].size()) return 0;
       if(dp[row][c1][c2]!=0) return dp[row][c1][c2];

       int cherry=(c1==c2 ? grid[row][c1]:grid[row][c2]+grid[row][c1]);
       int temp1=grid[row][c1];
       int temp2=grid[row][c2];
       grid[row][c1]=0;
       grid[row][c2]=0;
       int maxC=0;
       for(int i=-1;i<=1;i++){
           for(int j=-1;j<=1;j++){
              maxC=max(maxC,maxCherry(grid,row+1,c1+i,c2+j,dp));
           }
       }
        grid[row][c1]=temp1;
        grid[row][c2]=temp2;
        return dp[row][c1][c2]=maxC+cherry;
}

    int cherryPickup(vector<vector<int>>& grid) {
         int r=grid.size();
         int c=grid[0].size();
         vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,0)));
         return maxCherry(grid,0,0,c-1,dp);
    }


// Tabulation code without space optimization
int cherryPickup(vector<vector<int>>& grid) {
         int r=grid.size();
         int c=grid[0].size();
         vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,0)));
         for(int i=r-1;i>=0;i--){
             for(int j=0;j<c;j++){
                 for(int k=0;k<c;k++){
                        int maxC=0;
                        int cherry=(j==k ? grid[i][j]:grid[i][j]+grid[i][k]);
                        for(int x=-1;x<=1;x++){
                           for(int y=-1;y<=1;y++){
                              if(i+1>=r || j+x>=c || k+y>=c || j+x<0 || k+y<0) continue;
                              maxC=max(maxC,dp[i+1][j+x][k+y]);
                           }
                        }
                        dp[i][j][k]=maxC+cherry;
                    }
             }
         }
        return dp[0][0][c-1];
    }


// Tabulation code with space optimization
int cherryPickup(vector<vector<int>> &grid) {
    // Write your code here
         int r=grid.size();
         int c=grid[0].size();
         vector<vector<int>> dp(c,vector<int>(c,0)),curr(c,vector<int>(c,0));
         for(int i=r-1;i>=0;i--){
             for(int j=0;j<c;j++){
                 for(int k=0;k<c;k++){
                        int maxC=0;
                        int cherry=(j==k ? grid[i][j]:grid[i][j]+grid[i][k]);
                        for(int x=-1;x<=1;x++){
                           for(int y=-1;y<=1;y++){
                              if(i+1>=r || j+x>=c || k+y>=c || j+x<0 || k+y<0) continue;
                              maxC=max(maxC,dp[j+x][k+y]);
                           }
                        }
                        curr[j][k]=maxC+cherry;
                    }
             }
             dp=curr;
         }
        return dp[0][c-1];
}