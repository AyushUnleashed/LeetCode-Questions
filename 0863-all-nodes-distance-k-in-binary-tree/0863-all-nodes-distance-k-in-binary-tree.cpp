/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parentMap){
        //BFS traversal
        if(root==NULL) return;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while(pendingNodes.size()!=0){
            //
            TreeNode* curr = pendingNodes.front();
            pendingNodes.pop();
            
            if(curr->left){
                pendingNodes.push(curr->left);
                parentMap[curr->left]=curr;
            }
            
            if(curr->right){
                pendingNodes.push(curr->right);
                parentMap[curr->right]=curr;
            }
        }
    }
    
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root==NULL) return ans;
        unordered_map<TreeNode*,TreeNode*> parentMap; // node -> parent
        markParents(root,parentMap);
        
        //BFS
        // make visited hashmap
        unordered_map<TreeNode*,bool> visited; // node -> isVisited
        
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(target);
        visited[target]=true;
    
        int dis=0;
        while(pendingNodes.size()!=0){
            
            if(dis==k) break;
            dis++;
            int size = pendingNodes.size();
            
            for(int i=0;i<size;i++){
                // front
                TreeNode* curr = pendingNodes.front();
                pendingNodes.pop(); 
                // left
                if(curr->left && !visited[curr->left]){
                    visited[curr->left]=true;
                    pendingNodes.push(curr->left);
                }
                //right
                if(curr->right && !visited[curr->right]){
                    visited[curr->right]=true;
                    pendingNodes.push(curr->right);
                }
                //top  
                if( parentMap[curr] && !visited[parentMap[curr]]){
                    visited[parentMap[curr]]=true;
                    pendingNodes.push(parentMap[curr]);
                }
            }
        }
       
        int sz = pendingNodes.size();
        for(int i=0;i<sz;i++){
            TreeNode* curr = pendingNodes.front();
            pendingNodes.pop();
            ans.push_back(curr->val);
        }
        
        return ans;
    
    }
};