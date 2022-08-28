    #include<iostream>
    #include<vector>
    using namespace std;
    
    // Leetcode

    // Memoization method
    int maxMoney(vector<int> &nums,int index,vector<int> &dp){
           if(index>=nums.size()){
               return 0;
           }
            
            if(dp[index]!=-1) return dp[index];
            
            int m1=nums[index]+maxMoney(nums,index+2,dp);
            int m2=maxMoney(nums,index+1,dp);
        
            return dp[index]=max(m1,m2);
    }
    
    // Tabulation method with space optimization
    int rob(vector<int>& nums) {
        int n=nums.size();
        int after1=0;
        int after2=0;
        for(int i=n-1;i>=0;i--){
            int m1=nums[i]+after2;
            int m2=after1;
            after2=after1;
            after1=max(m1,m2);
        }
        return after1;
    }