#include<iostream>
#include<vector>
using namespace std;

// Coding ninjas

// Tabulation code
// This problem is mixture of 15 and 14
int countPartitions(int n, int d, vector<int> &nums) {
    // Write your code here.
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum=sum+nums[i];
    }
    vector<int> prev(sum+1,0),curr(sum+1,0);
    for(int target=0;target<=sum;target++){
       int x=(target==0 ? 1 :0);
       int y=0;
       if(nums[0]<=target) y=((target-nums[0]==0 ? 1:0));
       prev[target]=x+y;
    }
    for(int i=1;i<nums.size();i++){
        for(int target=0;target<=sum;target++){
                int x=(prev[target])%(int)(1e9+7);
                int y=0;
                if(nums[i]<=target) y=(prev[target-nums[i]])%(int)(1e9+7);
                curr[target]=(x+y)%(int)(1e9+7);
        }
        prev=curr;
    }
    int count=0;
    for(int i=0;i<=sum;i++){
        if(prev[i]!=0){
            int s1=i;
            int s2=sum-s1;
            if(s1>=s2 && s1-s2==d) count=(count+prev[i])%(int)(1e9+7);
        }
    }
    return count;
}


