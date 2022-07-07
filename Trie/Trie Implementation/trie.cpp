#include<iostream>
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

            if(root->children[word[0]-'A']!=NULL){
                child=root->children[word[0]-'A'];
            }
            else{
                child=new TrieNode(word[0]);
                root->children[word[0]-'A']=child;
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
        if(root->children[word[0]-'A']!=NULL){
            child=root->children[word[0]-'A'];
        }
        else{
            return false;
        }
        
        return searchWordUtil(child,word.substr(1));
        
    }

    bool searchWord(string word){
        return searchWordUtil(root,word);
    }
};


int main(){
    Trie *t=new Trie();
    t->insertWord("ARMED");
    cout<<t->searchWord("ARM");
    cout<<t->searchWord("ARMED");
    return 0;
}