#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

// Leetcode
 int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> freq;
        int length=0;
        for(int i=0;i<words.size();i++){
            string rev=words[i];
            reverse(rev.begin(),rev.end());
            if(freq[rev]>0){
                length+=4;
                freq[rev]--;
            }
            else{
                freq[words[i]]++;
            }
        }
        for(auto it:freq){
            if(it.first[0]==it.first[1] && freq[it.first]>0){
                length+=2;
                break;
            }
        }
        return length;
    }