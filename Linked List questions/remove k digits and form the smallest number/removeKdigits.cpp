#include<iostream>
using namespace std;


string removeKDigits(string &s,int k){
    string ans="";
    int ans_digit=s.length()-k;
    int count=0;
    int sm_index=-1;
    int m=0;
    while(count!=ans_digit){
        char smNo=58;
        for(int i=sm_index+1;i<=s.length()-ans_digit+count;i++){
            if(s[i]<smNo){
                smNo=s[i];
                sm_index=i;
            }
        }
        if(smNo=='0'){
            if(m!=0){
                ans=ans+smNo;
                m++;
            }
        }
        else{
            ans=ans+smNo;    
            m++;            
        }
        count++;
    }
    if(ans==""){
        return "0";
    }
    return ans;
}

int main(){
    string s="1432219";
    int k=3;
    cout<<removeKDigits(s,k);

    return 0;
}