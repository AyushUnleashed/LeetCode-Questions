class Solution {
public:
    vector<string> dp;
    
    
    string generate(string smallAns){
        int count=0;
        string newAns="";
        
        int size = smallAns.length();
        for(int i=0;i<size-1;i++){
            count++;
            if(smallAns[i]!=smallAns[i+1]){
                string cnt = to_string(count);
                newAns+=cnt+smallAns[i];
                count=0;
            }
        }
        count++;
        string cnt = to_string(count);
        newAns+=cnt+smallAns[size-1];
        return newAns;
    }
    
    string helper(int n){
       if(n==1){
           return "1";
       } 
        if(dp[n]!=""){
            return dp[n];
        }
        string smallAns = helper(n-1);
        string newAns = generate(smallAns);
        dp[n]=newAns;
        
        return newAns;
    }
    string countAndSay(int n) {
        dp.resize(31,"");
        dp[1]="1";
        return helper(n);
    }
};