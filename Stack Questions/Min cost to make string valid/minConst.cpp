#include<iostream>
#include<stack>
using namespace std;

int minCost(string s) {
  // Write your code here
    stack<char> temp;
    if(s.length()==0){
        return 0;
    }
    if(s.length()==1){
		return -1;
    }
    
    temp.push(s[0]);
    int op=0;
    for(int i=1;i<s.length();i++){
        if(!temp.empty() && s[i]=='}' && temp.top()=='{'){
            temp.pop();
        }
        else{
            temp.push(s[i]);
        }
    }
    if(temp.empty()){
        return 0;
    }
    if(temp.size()==1){
        return -1;
    }
    while(!temp.empty()){
        if(temp.top()=='}'){
            temp.pop();
            if(temp.empty()){
                break;
            }
            if(temp.top()=='{'){
               temp.pop();
            }
            else if(temp.top()=='}'){
                op++;
                temp.pop();
            }
        }
        else if(temp.top()='{'){
            temp.pop();
            if(temp.empty()){
                break;
            }
            if(temp.top()=='{'){
                op++;
                temp.pop();
            }
            else if(temp.top()=='}'){
                op=op+2;
                temp.pop();
            }
        }
    }
  
    return op;
}


int main(){
    string s="}{{}}{{{";
    cout<<minCost(s);
}