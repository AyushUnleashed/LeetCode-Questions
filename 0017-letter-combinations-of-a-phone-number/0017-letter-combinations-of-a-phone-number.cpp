class Solution {
public:
    
    vector<string> helper(string digits,vector<string> mp){
        vector<string> ans;
        if(digits.size()==0){
            ans.push_back("");
            return ans;
        }
        vector<string> smallAns = helper(digits.substr(1),mp);
        int idx = digits[0]-'0';
        string curr = mp[idx];
        for(int i=0;i<curr.length();i++){
            for(int j=0;j<smallAns.size();j++){
                
                ans.push_back(curr[i]+smallAns[j]);
            }
        }
        return ans;
        
    }
    vector<string> letterCombinations(string digits){
        vector<string> empty;
        if(digits.size()==0) return empty;
        vector<string> mp(10,"");
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        return helper(digits,mp);
    }
};