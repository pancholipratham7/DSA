 #include<iostream>
#include<vector>
#include<unordered_map>
 using namespace std;

// #Leetcode
 bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> occurence;
        for(int i=0;i<nums.size();i++){
            if(occurence[nums[i]]==0) occurence[nums[i]]=i+1;
            else{
                if(i+1-(occurence[nums[i]])<=k) return true;
                else occurence[nums[i]]=i+1;
            }
        }
        return false;
    }