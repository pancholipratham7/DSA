 #include<iostream>
 #include<vector>
 using namespace std;
 
//  GFG CODE

//  Memoization Code

 int findMaxProfit(int weight[],int value[],int n,int maxWeight,vector<vector<int>> &dp){
        
        if(maxWeight==0) return 0;  
      
        if(n==0){
            if(weight[n]<=maxWeight) return value[n];
            return 0;
        }
        
        if(dp[n][maxWeight]!=-1) return dp[n][maxWeight];
    
      //Notpick item       
      int p1=findMaxProfit(weight,value,n-1,maxWeight,dp);
    
      //Pick Item       
      int p2=0;
      if(weight[n]<=maxWeight) p2=value[n]+findMaxProfit(weight,value,n-1,maxWeight-weight[n],dp);
    
      return dp[n][maxWeight]=max(p1,p2);
}
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int>(W+1,-1));
       return findMaxProfit(wt,val,n-1,W,dp);
    }


// Tabulation code without space optimization
 int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int>(W+1,0));
  
       
       for(int i=0;i<=W;i++){
           if(wt[0]<=i) dp[0][i]=val[0];
           else dp[0][i]=0;
       }
       
       for(int i=1;i<n;i++){
           for(int weight=0;weight<=W;weight++){
                 
                 //NotPick Item   
                  int p1=dp[i-1][weight];
                
                  //Pick Item       
                  int p2=0;
                  if(wt[i]<=weight) p2=val[i]+dp[i-1][weight-wt[i]];
                  
                
                  dp[i][weight]=max(p1,p2);
            }
       }
       
       return dp[n-1][W];
    }


// Tabulation code without space opitmization
 int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<int> prev(W+1,0),curr(W+1,0);
  
       
       for(int i=0;i<=W;i++){
           if(wt[0]<=i) prev[i]=val[0];
           else prev[i]=0;
       }
       
       for(int i=1;i<n;i++){
           for(int weight=0;weight<=W;weight++){
                 
                 //NotPick Item   
                  int p1=prev[weight];
                
                  //Pick Item       
                  int p2=0;
                  if(wt[i]<=weight) p2=val[i]+prev[weight-wt[i]];
                  
                
                  curr[weight]=max(p1,p2);
            }
            prev=curr;
       }
       
       return prev[W];
    }


// Tabulation method one row space optimization without using prev
// Here we just need to start weight from maxWeight to 0
// We can use this optimization because we just need previous values

    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<int> curr(W+1,0);
  
       
       for(int i=0;i<=W;i++){
           if(wt[0]<=i) curr[i]=val[0];
           else curr[i]=0;
       }
       
       for(int i=1;i<n;i++){
           for(int weight=W;weight>=0;weight--){
                 
                 //NotPick Item   
                  int p1=curr[weight];
                
                  //Pick Item       
                  int p2=0;
                  if(wt[i]<=weight) p2=val[i]+curr[weight-wt[i]];
                  curr[weight]=max(p1,p2);
           }
       }
       
       return curr[W];
    }