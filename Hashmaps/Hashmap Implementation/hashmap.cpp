#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    // creation
    unordered_map<string,int> m;

    // insertion

    // 1
    pair<string,int> p1=make_pair("Pratham",1);
    m.insert(p1);

    // 2
    pair<string,int> p2("Raj",2);
    m.insert(p2);

    // 3
    m["Kartik"]=3;
    // this will update
    m["Kartik"]=4;

    
    // searching
    //1 
    cout<<m["Pratham"]<<endl;

    // 2
    cout<<m.at("Raj")<<endl;

    //If you try to access a unknown key
    // Difference between the two statements
     // this will throw error
    cout<<m.at("unknownkey")<<endl;
    // this will create a key value pair with unknown=0
    cout<<m["unknownkey"]<<endl;
    // So now if you run m.at("unknownkey") it will not throw error it will print 0

    // size
    cout<<m.size()<<endl;

    // if you want to find whether a key is present or not
    // if absent then it will return 0 otherwise if present then it will return 1
    cout<<m.count("bro")<<endl;

    // erase
    // it will erase the key value pair
    cout<<m.erase("Raj");


    // traversing the map
    // 1
    // In unordered map the values will not be printed in the order you inserted it will be random
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    // 2 using iterator
    unordered_map<string,int>:: iterator it=m.begin();
    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    // in ordered map values will be printed in the same order you inserted
    map<string,int> m1;
    m1["Pratham"]=1;
    m1["Raj"]=2;
    m1["Kartik"]=3;
    for(auto i:m1){
        cout<<i.first<<" "<<i.second<<endl;
    }

   

    return 0;
}