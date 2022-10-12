#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int perimeter=0;
        for(int i=nums.size()-1;i>=2;i--){
            if(nums[i]<nums[i-1]+nums[i-2]) {
                return nums[i]+nums[i-1]+nums[i-2];
            }
            
        }
        return perimeter;
        
    }