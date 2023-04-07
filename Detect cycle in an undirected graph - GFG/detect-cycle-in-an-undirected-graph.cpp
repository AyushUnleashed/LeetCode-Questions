//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    
    bool dfs(int vertex,vector<int> adj[],bool vis[],int parent){
        
        vis[vertex]=true;
        
        bool ans = false;
        for(int child:adj[vertex]){
            
            if(vis[child]==true && child==parent) continue;
            if(vis[child]==true && child!=parent) return true;
            ans= ans | dfs(child,adj,vis,vertex);
        }
        
        return ans;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        bool vis[V];
        for(int i=0;i<V;i++){
            vis[i]=false;
        }
        
        bool ans=false;
        
        for(int i=0;i<V;i++){
            if(vis[i]) continue;
            ans = dfs(i,adj,vis,-1);
            if(ans==true) break;
        }
        return ans;
        
    }
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends