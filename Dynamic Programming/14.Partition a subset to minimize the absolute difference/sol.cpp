#include<vector>
#include<iostream>
using namespace std;
#include<limits.h>

// #codestudio

// Here we will use the concept of previous question subset sum k
// So the dp matrix during this question for eg dp[i][target] will have value true or false
// It will denote that from ith index to 0 index can you form a subset subsequence with sum equals to target or not
// This concept we will apply in this question

// Here s1 and s2 are the two subsets formed after partition
// Now if i find all possible s1 then from s1 i can find s2(total_sum-s1)
// And in this way by finding all s1 we can find all s2 and then find the difference between (S1 and s2) and morever we can find minimum difference between s1 and s2
// Now s1 can have sum from 0(if i don't include anything in s1) upto (total_sum) (if i include all the elements in s1)
// now between this range we can check every number(target) whether we can form a subset with this number(target) or not by using dp[n][target]
// and if for a target we can form a subset(s1) then we will find the corresponing s2 and note the difference between them and update the min_diff variable
// and so on....


int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
    int total_sum=0;
    for(int i=0;i<arr.size();i++){
        total_sum+=arr[i];
    }
    
    vector<vector<bool>> dp(n,vector<bool>(total_sum+1,0));
    dp[0][arr[0]]=true;
    for(int i=0;i<n;i++) dp[i][0]=true;
    for(int i=1;i<n;i++){
        for(int target=1;target<=total_sum;target++){
            bool notPick=dp[i-1][target];
            bool pick=false;
            if(arr[i]<=target) pick=dp[i-1][target-arr[i]];
            dp[i][target]=(pick || notPick);
        }
    }
    int minDiff=INT_MAX;
    for(int i=0;i<=total_sum;i++){
        if(dp[n-1][i]){
            int s1=i;
            int s2=total_sum-i;
            if(minDiff>abs(s1-s2)) minDiff=abs(s1-s2);
        } 
    }
    return minDiff;
}
