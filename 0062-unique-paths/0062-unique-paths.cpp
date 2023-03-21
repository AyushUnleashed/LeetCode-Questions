class Solution {
    vector<vector<int>> dp;
public:
    
    int uniquePathsHelper(int x,int y,int m, int n){
        int totalPaths=0;
        if(x==n-1 || y==m-1){
            return 1;
        }
        if(x>=n || y>=m ){
            return 0;
        }
        int rightCall;
        if(dp[x+1][y]==-1){
            rightCall =uniquePathsHelper(x+1,y,m,n);
            dp[x+1][y] = rightCall;
        }else{
            rightCall = dp[x+1][y];
        }
        
        int bottomCall;
        if(dp[x][y+1]==-1){
            bottomCall =uniquePathsHelper(x,y+1,m,n);
            dp[x][y+1] = bottomCall;
        }else{
            bottomCall = dp[x][y+1];
        }
    
        
        totalPaths = rightCall + bottomCall;
        return totalPaths;
    }
    
    
    int uniquePaths(int m, int n) {
        int x =0,y=0;

        for(int i=0;i<n;i++){
            vector<int> curr(m,-1);
            dp.push_back(curr);
        }
        return uniquePathsHelper(x,y,m,n);
    }
};