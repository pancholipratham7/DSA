 #include<iostream>
 #include<vector>
 using namespace std;

    // Leetcode
    

    //Memoization Code 
    int findWays(vector<int> &coins,int amount,int n,vector<vector<int>> &dp){
        
        if(amount==0) return 1;
        if(n==0){
            return (amount%coins[n]==0);
        }
        if(dp[n][amount]!=-1) return dp[n][amount];
        
        int notPick=findWays(coins,amount,n-1,dp);
        int pick=0;
        if(coins[n]<=amount) pick=findWays(coins,amount-coins[n],n,dp);
        
        return dp[n][amount]=pick+notPick;
        
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return findWays(coins,amount,coins.size()-1,dp);
    }


    // Tabulation Code without space optimization
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,0));
        
        for(int i=0;i<coins.size();i++){
            dp[i][0]=1;
        }
        
        for(int target=0;target<=amount;target++){
            dp[0][target]=(target%coins[0]==0);
        }
        
        for(int i=1;i<coins.size();i++){
            for(int target=1;target<=amount;target++){
                int notPick=dp[i-1][target];
                int pick=0;
                if(coins[i]<=target) pick=dp[i][target-coins[i]];
                dp[i][target]=pick+notPick;
            }
        }
        return dp[coins.size()-1][amount];
    }

