#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    // this will help us to find whether the node is terminal or not
    bool isTerminal;

    TrieNode(char data){
        this->data=data;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        this->isTerminal=false;
    }
};

class Trie{
    public:
    TrieNode *root;
    Trie(){
        this->root=new TrieNode('\0');
    }
    
    void insertUtil(TrieNode*root,string word){

            if(word.length()==0){
                root->isTerminal=true;
                return;
            }

            TrieNode* child;

            if(root->children[word[0]-'a']!=NULL){
                child=root->children[word[0]-'a'];
            }
            else{
                child=new TrieNode(word[0]);
                root->children[word[0]-'a']=child;
            }
            insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }

    bool searchWordUtil(TrieNode*root,string word){
        
        if(word.length()==0){
            return root->isTerminal;
        }

        TrieNode *child;
        if(root->children[word[0]-'a']!=NULL){
            child=root->children[word[0]-'a'];
        }
        else{
            return false;
        }
        
        return searchWordUtil(child,word.substr(1));
        
    }

    bool searchWord(string word){
        return searchWordUtil(root,word);
    }

    string longestPrefix(){
        string temp="";
        TrieNode *a=root;
        while(a){
            int counter=0;
            TrieNode *child=NULL;
            for(int i=0;i<26;i++){
                    if(a->children[i]!=NULL){
                            counter++;
                            if(counter>1){
                                a=NULL;
                                break;
                            }
                        child=a->children[i];
                 }
            }
            if(a!=NULL){
                a=child;
                temp=temp+(child->data);
            }
        }
        return temp;
    }

};


int main(){
    Trie *t=new Trie();

    vector<string> s;
    s.push_back("abcdefgh");
    s.push_back("aefghijk");
    s.push_back("abcefgh");


    for(int i=0;i<s.size();i++){
        t->insertWord(s[i]);
    }

    cout<<t->longestPrefix();


    return 0;
}