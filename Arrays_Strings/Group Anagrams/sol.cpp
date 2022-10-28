 #include<iostream>
 #include<vector>
 #include<algorithm>
 #include<unordered_map>
 using namespace std;

 vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++){
            string str=strs[i];
            sort(strs[i].begin(),strs[i].end());
            m[strs[i]].push_back(str);
        }
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }