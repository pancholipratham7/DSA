#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class TimeMap {
public:
    unordered_map<string,unordered_map<int,string>> info;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        info[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if(info[key].size()==0) return "";
        if(info[key][timestamp]!="") return info[key][timestamp];
        string val="";
        for(int i=timestamp;i>=1;i--){
            if(info[key][i]!="") {
                val=info[key][i];
                break;
            }
        }
        return val;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */