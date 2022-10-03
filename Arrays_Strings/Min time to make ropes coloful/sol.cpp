 #include<iostream>
 #include<vector>
 #include<algorithm>
 #include<string.h>
 using namespace std;

// @Leetcode
 int minCost(string colors, vector<int>& time) {
        int maxCost=0;
        int cost=time[0];
        int largest=time[0];
        
        for(int i=1;i<colors.size();i++){
            if(colors[i]!=colors[i-1]){
                maxCost+=(cost-largest);
                cost=time[i];
                largest=time[i];
            }
            else{
                largest=max(largest,time[i]);
                cost+=time[i];
            }
        }
        maxCost+=cost-largest;
        return maxCost;
    }