#include<iostream>
#include<vector>
using namespace std;

// @lEETCODE
 bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string temp1="";
        string temp2="";
        int index1=0,i1=0;
        int index2=0,i2=0;
        while(index1<word1.size() && index2<word2.size()){
            if(word1[index1][i1]!=word2[index2][i2]) return false;
            else{
                i1++;
                i2++;
                if(i1>=word1[index1].size()){
                    i1=0;
                    index1++;
                }
                if(i2>=word2[index2].size()){
                    i2=0;
                    index2++;
                }
            }
        }
        if(index1<word1.size() || index2<word2.size()) return false;
        return true;
    }