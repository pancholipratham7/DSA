#include<iostream>
#include<stack>
using namespace std;

bool redundant(string &s){
    bool ans=true;
    stack<char> temp;
    temp.push(s[0]);
    for(int i=0;i<s.length();i++){
         if(temp.empty() || s[i]=='(' || s[i]=='*' || s[i]=='/' || s[i]=='+' || s[i]=='-') {
            temp.push(s[i]);
        }
        else if(s[i]==')'){
            if(temp.top()=='('){
                return true;
            }
            else{
                while(temp.top()!='('){
                    temp.pop();
                }
                temp.pop();
            }    
            
        }
       
    }


    return false;
}

int main(){
    string s="(a+b)*(c-d)";
    if(redundant(s)){
        cout<<"Redundant brackets found"<<endl;
    }
    else{
        cout<<"No redundant brackets found"<<endl;
    }
    return 0;
}