#include<iostream>
#include<vector>
using namespace std;

// This is the code after doing the space optimization of the tabulation method

int frogJump(int n, vector<int> &heights)
{
     int prev2=0;
     int prev1=abs(heights[0]-heights[1]);
    for(int i=3;i<=n;i++){
        int e1=abs(heights[i-2]-heights[i-1])+prev1;
        int e2=abs(heights[i-3]-heights[i-1])+prev2;
        prev2=prev1;
        prev1=min(e1,e2);
    }
    
     return prev1;
}