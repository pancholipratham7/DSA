#include<iostream>
#include<vector>
#include<string>
using namespace std; 
 
vector<int> findAnagrams(string txt, string pat) {
        vector<int> ans;
        if(pat.length()>txt.length()) return ans;
	    int w_size=pat.length();
	    int i=0,j=0;
	    int freqp[26]={0};
	    int freqt[26]={0};
	    for(int x=0;x<pat.length();x++){
	        freqp[pat[x]-'a']++;
	    }
	    while(j<txt.length()){
	        freqt[txt[j]-'a']++;
	        if(j-i+1==w_size){
	            bool anagram=true;
	            for(int x=0;x<26;x++){
                     if(freqp[x]!=freqt[x]){
	                    anagram=false;
	                    break;
                    }
	            }
	            if(anagram) ans.push_back(i);
	            freqt[txt[i]-'a']--;
	            i++;
	        }
	        j++;
	    }
	    return ans;
    }