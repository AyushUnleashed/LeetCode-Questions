#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode** children; 
    bool isTerminal;
    
    TrieNode(char data){
        this->data = data;
        this->children = new TrieNode*[26];
        for(int i=0;i<26;i++){
            this->children[i]=NULL;
        }
        this->isTerminal = false;
    }
};



class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertHelper(string word,TrieNode* root){
        if(word.size()==0){
            //end of word
            root->isTerminal = true;
            return;
        }
        // if word is not empty
        // create node of first character
        int idx = word[0]-'a';
        TrieNode* child=NULL;
        if(root->children[idx]==NULL){
            child = new TrieNode(word[0]);
            root->children[idx]=child;
        }else{
            child = root->children[idx];
        }
        insertHelper(word.substr(1),child);
    }
    void insert(string word) {
        insertHelper(word,root);
    }
    
    bool searchHelper(string word,TrieNode* root){
        if(word.size()==0){
            //end of word
            return root->isTerminal;
        }
        TrieNode* child=NULL;
        int idx = word[0]-'a';
         if(root->children[idx]==NULL){
            return false;
        }else{
             
         }
        bool ans = searchHelper(word.substr(1),root->children[idx]);
        return ans;
    }
    
    bool search(string word) {
        return searchHelper(word,root);
    }
    
    bool startWithHelper(string prefix,TrieNode* root){
        if(prefix.size()==0){
            //end of word
            return true;
        }
        int idx = prefix[0]-'a';
         if(root->children[idx]==NULL){
            return false;
        }
        bool ans = startWithHelper(prefix.substr(1),root->children[idx]);
        return ans;
    }
    
    
    bool startsWith(string prefix) {
        return startWithHelper(prefix,root);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */