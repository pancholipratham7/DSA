#include<iostream>
#include<vector>
using namespace std;


// Leetcode

 int totalFruit(vector<int>& fruits) {
        int x=-1,y=-1,i=0,j=0;
        int maxFruits=0;
        while(j<fruits.size()){
            if(x==-1 || fruits[j]==fruits[x]){
                if(maxFruits<j-i+1) maxFruits=j-i+1;
                x=j;
                j++;
                continue;
            }
              if(y==-1 || fruits[j]==fruits[y]){
                if(maxFruits<j-i+1) maxFruits=j-i+1;
                y=j;
                j++;
                continue;
            }
            if(x>y){
                i=y+1;
                x=j-1;
                y=j;
            }
            else{
                i=x+1;
                x=j-1;
                y=j;
            }
            j++;
        }
        return maxFruits;
    }