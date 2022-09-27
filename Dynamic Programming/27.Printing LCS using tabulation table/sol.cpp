// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;


int main() {
    // Write C++ code here
    string s1="acdef";
    string s2="azbexyf";
    int n1=s1.length();
    int n2=s2.length();
    
    vector<vector<int>> dp(n1,vector<int>(n2,0));
    for(int i=0;i<n2;i++){
        if(s1[0]==s2[i]) dp[0][i]=1;
        else dp[0][i]=(i-1>=0 ? dp[0][i-1] : 0);
    }
    
    for(int i=0;i<n1;i++){
        if(s1[i]==s2[0]) dp[i][0]=1;
        else dp[i][0]=(i-1>=0 ? dp[i-1][0]:0);
    }
    
    
    for(int i=1;i<n1;i++){
        for(int j=1;j<n2;j++){
            if(s1[i]==s2[j]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string ans="";
    while(n1>=0 && n2>=0){
        if(s1[n1]==s2[n2]) {
            ans=s1[n1]+ans;
            n1--;
            n2--;
        }
        else{
            if(dp[n1-1][n2]>dp[n1][n2-1]) {
                n1--;
            } 
            else n2--;
        }
    }
    // (for the last character that is ="")
    ans.pop_back();
    cout<<ans;
    
    return 0;
}