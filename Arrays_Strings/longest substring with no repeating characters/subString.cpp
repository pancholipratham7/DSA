#include<iostream>
#include<string>
using namespace std;

int largestSubstring(string s){
    if(s.length()==0){
        return 0;
    }
    int temp[26]={-1};
    int maxLength=1;
    int length=1;
    int base_Index=0;
    temp[int(s[0])]=0;
    for(int i=1;i<s.length();i++){
        if(temp[int(s[i])]>=base_Index){
            length=length-(temp[int(s[i])]-base_Index);
            base_Index=temp[int(s[i])]+1;
        }
        else{
            length++;
            if(maxLength<length){
                maxLength=length;
            }
        }
        if(temp[int(s[i])]<base_Index){
            temp[int(s[i])]=i;
        }
    }
    return maxLength;
}

int main(){
    string s;
    cin>>s;
    cout<<"The length of the largest substring with no repeating characters is="<<largestSubstring(s);
    return 0;
}