class Solution {
    vector<vector<int>> dp;
public:
    
    int uniquePathsHelper(int x,int y,int m, int n){
        
        if(x==n-1 || y==m-1) return 1;
        if(x>=n || y>=m ) return 0;
        
        if(dp[x][y]) return dp[x][y];
        
        int rightCall =uniquePathsHelper(x+1,y,m,n);
        int bottomCall =uniquePathsHelper(x,y+1,m,n);
        
        int totalPaths = rightCall + bottomCall;
        dp[x][y]=totalPaths;
        
        return totalPaths;
    }
    
    
    int uniquePaths(int m, int n) {
        int x =0,y=0;

        dp.resize(n,vector<int> (m,0));
        return uniquePathsHelper(x,y,m,n);
    }
};