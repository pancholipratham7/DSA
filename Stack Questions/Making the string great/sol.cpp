 #include<iostream>
 #include<stack>
 using namespace std;

//  @Leetcode
 string makeGood(string s) {
        stack<char> temp;
        int i=0;
        while(i<s.length()){
            int top;
            if(!temp.empty()) top=temp.top();
            if(!temp.empty() && ((isupper(top) && islower(s[i]) && tolower(top)==s[i] )||(islower(top) && isupper(s[i]) && toupper(top)==s[i]))) temp.pop();
            else temp.push(s[i]);
            i++;
        }
        string ans="";
        while(!temp.empty()){
            ans=temp.top()+ans;
            temp.pop();
        }
        return ans;
    }