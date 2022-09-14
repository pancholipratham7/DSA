 #include<iostream>
 #include<vector>
 using namespace std;
 

// Here for writing memoization code three variables  will be required
// And in majority of the problems we will use only two variables
// So we will write the tabulation code for this
// Think and try out that how can we fill the tabulation table 
// This question is a little bit different
// And we will be filling the table in a different way

//  Tabulation code with space optimization
    int longestCommonSubstr (string S1, string S2, int n,int m)
    {
        // your code here
        vector<int> prev(m+1,0),curr(m+1,0);
        
        int maxLength=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(S1[i-1]==S2[j-1]) {
                    curr[j]=1+prev[j-1];
                    maxLength=max(maxLength,curr[j]);
                }
                else curr[j]=0;
            }
            prev=curr;
        }
        return maxLength;
        
    }