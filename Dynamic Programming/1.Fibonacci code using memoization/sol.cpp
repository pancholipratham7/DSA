#include<iostream>
#include<vector>
using namespace std;

int fibonacci(int n,vector<int> &dp){
    if(n<=1) return -1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp);
}

int main(){
    int n;
    cin>>n;
    vector<int> dp;
    cout<<fibonacci(n,dp);
    return 0;
}