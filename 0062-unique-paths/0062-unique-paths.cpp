class Solution {
    vector<vector<int>> dp;
public:
    
    int uniquePathsHelper(int i,int j,int m, int n){
        
        if(i==m-1 || j==n-1) return 1;
        if(i>=m || j>=n ) return 0;
        
        if(dp[i][j]) return dp[i][j];
        
        int rightCall =uniquePathsHelper(i,j+1,m,n);
        int bottomCall =uniquePathsHelper(i+1,j,m,n);
        
        int totalPaths = rightCall + bottomCall;
        dp[i][j]=totalPaths;
        
        return totalPaths;
    }
    
    
    int uniquePaths(int m, int n) {
        int i=0,j=0;

        dp.resize(m,vector<int> (n,0));
        return uniquePathsHelper(i,j,m,n);
    }
};