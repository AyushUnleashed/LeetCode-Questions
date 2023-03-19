class TrieNode{
    public:
    char data;
    TrieNode** children;
    bool isTerminal;
    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal=false;
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode('\0');
    }
    
    void addWordHelper(string word,TrieNode* root){
        if(word.size()==0){
            root->isTerminal=true;
            return;
        }
        int idx = word[0]-'a';
        if(root->children[idx]==NULL){
            root->children[idx]= new TrieNode(word[0]);
        }
        addWordHelper(word.substr(1),root->children[idx]);
    }
    
    void addWord(string word) {
        addWordHelper(word,root);
    }
    
    bool searchWordHelper(string word,TrieNode* root){

        if(word.size()==0){
            return root->isTerminal;
        }
        if(word[0]=='.'){
            for(int i=0;i<26;i++){
                if(root->children[i]==NULL ) continue;
                //not null
                bool curr =searchWordHelper(word.substr(1),root->children[i]);
                if(curr==true){
                    return true;
                }
            }
            return false;
        }
        int idx = word[0]-'a';
        if(root->children[idx]==NULL){
            return false;
        }
        return searchWordHelper(word.substr(1),root->children[idx]);
    }
    
    bool search(string word) {
        return searchWordHelper(word,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */