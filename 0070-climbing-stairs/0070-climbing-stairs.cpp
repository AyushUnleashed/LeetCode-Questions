class Solution {
    
public:
    vector<int> dp;
    Solution(){
        vector<int> v(46,-1);
        dp = v;
    }
    
    int climbStairs(int n) {
        if(n<=2){
            return n;
        }
        if(dp[n]==-1){
           dp[n] = climbStairs(n-1)+climbStairs(n-2);  
        }
        return dp[n];
    }
};