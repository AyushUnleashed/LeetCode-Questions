class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> freqS;
        unordered_map<char,int> freqT;
        
        for(auto &c:s){
            freqS[c]++;
        }
        for(auto &c: t){
            freqT[c]++;
        }
        
        for(int i=0;i<t.size();i++){
            if(freqS[t[i]] != freqT[t[i]]){
                return t[i];
            }
        }
        return '-1';
        
    }
};