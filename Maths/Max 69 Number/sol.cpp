#include<iostream>
#include<math.h>
 using namespace std;

//  @Leetcode

 int maximum69Number (int num) {
        int idx=-1;
        int no=num;
        int i=0;
        while(no!=0){
            if(no%10==6) idx=i;
            no=no/10;
            i++;
        }
        if(idx==-1) return num;
        return num+(3*pow(10,idx));
    }