#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Codestudio Problem
vector<int> firstNegative(vector<int> arr, int n, int k) {
	// Write your code here.
    vector<int> ans;
    int i=0,j=0;
    queue<int> temp;
    while(j<n){
       if(j-i+1==k){
           if(arr[j]<0) temp.push(j);
           if(temp.empty()) ans.push_back(0);
           else ans.push_back(arr[temp.front()]);
           if(!temp.empty() && i==temp.front()) temp.pop();
           i++;
           j++;
       }
       else {
           if(arr[j]<0) temp.push(j);
           j++;
       }
    }
    return ans;
}