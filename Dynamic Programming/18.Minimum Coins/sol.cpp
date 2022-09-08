 #include<iostream>
 #include<vector>
 #include<limits.h>
 using namespace std;

// Code Studio

   //Memoization Code 
      int minElements(vector<int> &num,int x,int n,vector<vector<int>> &dp){
        if(x==0) return 0;
         if(n==0){
             if(x%num[n]==0) return x/num[n];
             return INT_MAX;
         }
       if(dp[n][x]!=-1) return dp[n][x];
    
      //not Pick
      int notPick=minElements(num,x,n-1,dp);
      
      //pick
      int pick=INT_MAX;
      if(num[n]<=x) {
          int elements=minElements(num,x-num[n],n,dp);
          if(elements!=INT_MAX) pick=elements+1;
      }
      return dp[n][x]=min(pick,notPick);
}

    
    int coinChange(vector<int>& num, int x) {
         vector<vector<int>> dp(num.size(),vector<int>(x+1,-1));
         int el=minElements(num,x,num.size()-1,dp);
         if(el==INT_MAX) return -1;
         return el;
    }


// Tabulation Code without space optimization
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(x+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=0;
    }
    for(int target=1;target<=x;target++){
        if(target % num[0]==0) dp[0][target]=target/num[0];
        else dp[0][target]=INT_MAX;
    }
    for(int i=1;i<n;i++){
        for(int target=1;target<=x;target++){
            int notPick=0+dp[i-1][target];
            int pick=INT_MAX;
            if(num[i]<=target){
                int el=dp[i][target-num[i]];
                if(el!=INT_MAX) pick=el+1;
            }
            dp[i][target]=min(pick,notPick);
        }
    }
    if(dp[n-1][x]==INT_MAX) return -1;
    return dp[n-1][x];
}