#include<iostream>
#include<vector>
#include<stack>
using namespace std;


void printVector(vector<int> ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

void calSpan(int prices[],int n){
    vector<int> ans(n,0);
    stack<int> s;
    s.push(n-1);
    for(int i=n-2;i>=0;i--){
        if(!s.empty() && prices[i]>prices[s.top()]){
                while(!s.empty() && prices[i]>prices[s.top()]){
                    ans[s.top()]=s.top()-i;
                    s.pop();
                }
                s.push(i);
        }
        else{
            s.push(i);
        }
    }

    while(!s.empty()){
        ans[s.top()]=s.top()+1;
        s.pop();
    }
    printVector(ans);
}


int main(){
    int prices[6]={10,4,5,90,120,80};
    int n=7;
    calSpan(prices,n);
    return 0;

}