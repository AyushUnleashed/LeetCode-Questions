#include <bits/stdc++.h> 

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans="";
        char temp ='-';
        
        // find minimum lengtj\h
        
        int minLength=INT_MAX;
        for(auto & str:strs)
        {
            if(minLength>str.length())
            {
                minLength = str.length();
            }
        }
        cout<<minLength<<endl;
        
        for(int i=0;i<minLength;i++)
        {
            for(auto & oneString:strs)
            {
                if(temp=='-')//  first time
                {
                    temp=oneString[i];
                }else
                {
                    if(oneString[i]!=temp)
                    {
                        // not common return ans;
                        return ans;
                    } 
                }    
            }
        
        ans+=temp;
        temp='-';
            
        }
        
        return ans;

            
            

            
    }
};