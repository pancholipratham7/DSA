 #include<iostream>
 #include<string>
 using namespace std;

//  @LEETCODE
 string countAndSay(int n) {
        if(n==1) return "1";
        string temp=countAndSay(n-1);
        string ans;
        char prev=temp[0];
        int count=1;
        for(int i=1;i<temp.size();i++){
            if(prev==temp[i]) count++;
            else{
                ans=ans+(to_string(count))+prev;
                prev=temp[i];
                count=1;
            }
        }
        ans=ans+(to_string(count))+prev;
        return ans;
    }