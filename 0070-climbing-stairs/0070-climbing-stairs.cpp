class Solution {
    
public:
    vector<int> dp;
    Solution(){
        vector<int> v(46,-1);
        dp = v;
    }
    
    int climbStairs(int n) {
        if(n==1 || n==2){
            return n;
        }
        int ans1,ans2;
        if(dp[n-1]!=-1){
           ans1 = dp[n-1]; 
        }else{
            ans1 = climbStairs(n-1);
            dp[n-1]=ans1;
        } 
        
        if(dp[n-2]!=-1){
           ans2 = dp[n-2]; 
        }else{
            ans2 = climbStairs(n-2);
            dp[n-2]=ans2;
        } 

        
        return ans1+ans2;
    }
};