#include<iostream>
#include<string>
using namespace std;


  int countUnique(int *freq,int k){
        int count=0;
        for(int i=0;i<26;i++){
            if(freq[i]>=1){
                count++;
            }
        }
        return count;
    }
  
    int longestKSubstr(string s, int k) {
    // your code here
    int i=0,j=0;
    int freq[26]={0};
    int maxLength=-1;
        while(j<s.length()){
            freq[s[j]-'a']++;
            int unique_char=countUnique(freq,k);
            if(unique_char==k){
                if(j-i+1>maxLength) maxLength=j-i+1;
            }
            else if(unique_char>k){
                freq[s[i]-'a']--;
                i++;
            }
            
            j++;
        }
        return maxLength;
    }