#include<iostream>
#include<vector>
using namespace std;

// CodeStudio Problem

// Tabulation Method

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(3,-1));
    int prev2=max(points[0][2],points[0][0]);
    int prev3=max(points[0][1],points[0][0]);
    int prev1=max(points[0][1],points[0][2]);
    
    
    for(int i=1;i<n;i++){
        int a,b,c;
        for(int j=0;j<3;j++){
            if(j==0) a=max(points[i][1]+prev2,points[i][2]+prev3); 
            else if(j==1) b=max(points[i][0]+prev1,points[i][2]+prev3);
            else c=max(points[i][0]+prev1,points[i][1]+prev2);
        }
        prev1=a;
        prev2=b;
        prev3=c;
    }
    int maxPoints=max(prev1,prev2);
    return  max(maxPoints,prev3);
}