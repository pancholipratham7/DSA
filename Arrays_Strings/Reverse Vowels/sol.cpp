#include<iostream>
using namespace std;

// @Leetcode
 bool isVowel(char val){
        string vowels="aeiouAEIOU";
        for(char x:vowels){
            if(x==val) return true;
        }
        return false;
    }
    
    string reverseVowels(string s) {
        int l=0;
        int r=s.length()-1;
        while(l<r){
            if(isVowel(s[l]) && isVowel(s[r])){
                swap(s[l],s[r]);
                l++;
                r--;
            }
            else{
                if(!isVowel(s[l])){
                    l++;
                }
                if(!isVowel(s[r])){
                    r--;
                }
            }
        }
        return s;
    }