#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
    return 0;
}

// t(n)=o(n) s(n)=o(n)
// Now here we can reduce the space complexity because for calculating nth fibonacii number  we just need only two previous values
// So instead of creating a dp vector we can create two variables which will keep track of prev1 and prev2 values