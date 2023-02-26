#include<bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<int,bool> dp;
public:
    
    bool wordBreakHelper(string str,int startIdx,unordered_set<string>& set){ 
        
        if(str=="" || startIdx==str.size()){
            return true;
        }
        
        if(dp.find(startIdx)!=dp.end()){
            return dp[startIdx];
        }
        
        string curr="";
        for(int i=startIdx;i<str.length();i++){
            curr+=str[i];
            if(set.find(curr)!=set.end()){
                //exist in map
                
                bool smallAns = wordBreakHelper(str,i+1,set);
                if(smallAns==true){
                    dp[startIdx]=true;
                    return true;
                }
            }
        }
        dp[startIdx]=false;
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