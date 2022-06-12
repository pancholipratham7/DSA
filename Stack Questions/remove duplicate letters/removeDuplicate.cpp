#include<iostream>
#include<stack>
using namespace std;

// @leetcode
// @ very important question
// same as leetcode question finding the smallest subsequence of a string containing distinct elements
// Approach:
// we will be using a stack to store unique characters and iterating over the string
// If any element occurs in the string which is already present in the stack we will not be adding that element to the stack
// if any element during the time of iteration is bigger than the stack top element we will be adding that element to the stack
// if any element during the time of iteration is smaller than the stack top element and stack top element last occurence is greater than current i then we will be removing the stack top elements till the s[i] is bigger than stack top element

string removeDuplicates(string s){
    stack<char> temp;
    temp.push(s[0]);

    // array for checking the element is visited or not (it is present in stack or not)
    bool x[26]={false};

    // this array is used for maintaining the  index of the last occurence of the element 
    int b[26];

    // updating the index of last occurence of the element
    for(int i=0;i<s.length();i++){
        b[s[i]-'a']=i;
    }

    for(int i=1;i<s.length();i++){
        // If the element is already present in the stack then there is no need to add this element in the stack
        if(x[s[i]-'a']){
            continue;
        }
        else{
            // if the element s[i] is smaller than the top element of the stack then we need to do this for maintaining the lexiographically string
            while(!temp.empty() && temp.top()>s[i] && b[temp.top()-'a']>i){
                x[temp.top()-'a']=false;
                temp.pop();
            }
            // adding the element to the stack
            temp.push(s[i]);
            // marking the element as visited
            x[s[i]-'a']=true;
        }
    }
    string result;
    // now the stack will contain the lexiographically smallest string
    while(!temp.empty()){
        result=temp.top()+result;
        temp.pop();
    }
    return result;
}

int main(){
    string s="cbacdcbc";
    cout<<removeDuplicates(s)<<endl;    
    return 0;
}