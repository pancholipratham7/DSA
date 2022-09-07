 #include<iostream>
 #include<vector>
 using namespace std;

// Leetcode

    void findNumbers(vector<int> &ans,int k,int n,int num,int ld){
        
        if(n==0){
            ans.push_back(num);
            return ;
        }
        
        if(ld+k>=0 && ld+k<=9){
            findNumbers(ans,k,n-1,num*10+(ld+k),ld+k);       
        }
        
        if(k!=0 && ld-k>=0 && ld-k<=9){
            findNumbers(ans,k,n-1,num*10+(ld-k),ld-k);
        }

    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            findNumbers(ans,k,n-1,i,i);
        }
        return ans;
    }