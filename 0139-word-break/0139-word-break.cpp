#include<bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<int,bool> dp;
public:
    
    bool wordBreakHelper(string str,int pos,unordered_set<string>& set){ 
        
        if(pos==str.size()){
            return true;
        }
        
        if(dp.find(pos)!=dp.end()){
            return dp[pos];
        }
        
        string curr="";
        for(int i=pos;i<str.length();i++){
            curr+=str[i];
            if(set.find(curr)!=set.end()){
                //exist in map
                
                bool smallAns = wordBreakHelper(str,i+1,set);
                if(smallAns==true){
                    dp[pos]=true;
                    return true;
                }
            }
        }
        dp[pos]=false;
        return false;
        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        //hashmap
        unordered_set<string> set;
        for(auto &s:wordDict){
           set.insert(s);
        }
        int pos=0;
        return wordBreakHelper(s,pos,set);
        
    }
};