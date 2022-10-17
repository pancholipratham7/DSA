#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i=s.length()-1;
        while(s[i]==' '){
            i--;
        }
        string ans;
        string temp;
        bool spaceFound=false;
        for(i;i>=0;i--){
            if(s[i]!=' ') {
                temp=s[i]+temp;
                spaceFound=false;
            }
            else{
                if(!spaceFound){
                    ans=ans+temp;
                    temp="";
                    ans.push_back(' ');
                    spaceFound=true;
                }
            }
        }
        if(temp!=""){
            ans=ans+temp;
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};