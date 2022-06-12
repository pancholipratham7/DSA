#include<iostream>
#include<stack>
using namespace std;

  int calMinAdd(string s) {
        stack<char> temp;
        temp.push(s[0]);
		
		//firstly removing the valid parenthesis from the string (valid parenthesis are those parenthesis which have opening as well as closing bracket)
        for(int i=1;i<s.size();i++){
            if(temp.empty() || s[i]=='('){
                temp.push(s[i]);
            }
            else if(s[i]==')'){
                if(temp.top()=='('){
                    temp.pop();
                }
                else{
                    temp.push(s[i]);
                }
            }
        }
        //the remaining brackets present in the string will be invalid and for each remaining bracket you need to add a corresponing opposite bracket so the min no of brackets you need to add will be equal to the remaining brackets in the string 
        return temp.size();
    }

int main(){

    string s="(((";
    cout<<calMinAdd(s)<<endl;

    return 0;
}