 #include<iostream>
 #include<vector>
 using namespace std;

 vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        int duplicate;
        int i=0;
        while(i<n){
            int x=nums[i]%n;
            if(x==i) i++;
            else{
                if(nums[i]==nums[x]){
                    duplicate=nums[i];
                    break;
                }
                else swap(nums[i],nums[x]);
            }
        }
        
        ans.push_back(duplicate);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        sum=sum-duplicate;
        int actualSum=(n*(n+1))/2;
        ans.push_back(actualSum-sum);
        return ans;
    }