#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Codestudio Problem
// First we will traverse the array and try to create a window of size K
// Window will be represented by i and j ,initially i will point to zero and while traversing we will do j++ and store the negative numbers in a queue temp
// once you reach the window size K then you need to remove the arr[i] element from window and to mark the first negative for this element we will look at  queue front() element
// If queue is empty the first negative for ith element will be 0
// and if this i element and queue front element are same then remove queue front element also
// For the next window we will do i++ and j++ and keep repeating the above process

// T(N)=O(N)
// Space complexity=O(k)

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