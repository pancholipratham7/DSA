#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

// @leetcode
int threeSumClosest(vector<int>& nums, int target) {
        int ans;
        int diff=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<=nums.size()-3;i++){
            int l=i+1;
            int e=nums.size()-1;
            while(l<e){
                int temp=nums[i]+nums[l]+nums[e];
                if(temp==target){
                    ans=target;
                    diff=0;
                    break;
                }
                else if(temp>target){
                    e--;
                }
                else{
                    l++;
                }
                 int x=abs(target-temp);
                 if(diff>x) {
                     diff=x;
                     ans=temp;
                 }
            }
            if(diff==0) break;
        }
        return ans;
        
    }