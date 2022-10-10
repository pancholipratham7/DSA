 #include<iostream>
 #include<vector>
 #include<string>
 using namespace std;

//  Leetcode
 string breakPalindrome(string palindrome) {
        int n=palindrome.length();
        if(n==1 || n==0) return "";
        int idx=-1;
        for(int i=0;i<n/2;i++){
            if(palindrome[i]!='a') {
                idx=i;
                break;
            }
        }
        
        if(idx!=-1) palindrome[idx]='a';
        else palindrome[n-1]='b';
        return palindrome;
    }