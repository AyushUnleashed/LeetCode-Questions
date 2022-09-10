/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> finalAns;
        if(root==NULL){
            return finalAns;
        }
        queue<TreeNode*> pendingNodes;
        
        pendingNodes.push(root);
        pendingNodes.push(NULL);
        
        vector<int> currLevel;
        while(pendingNodes.size()!=0){
        
            
            TreeNode* front = pendingNodes.front();
            pendingNodes.pop();
            
            if(front==NULL){
                    
                   finalAns.push_back(currLevel);
                    currLevel.clear();
                
                if(pendingNodes.size()==0){
                    break;
                }else{
                    pendingNodes.push(NULL);
                }
            }else{
                
                currLevel.push_back(front->val);
                
                if(front->left!=NULL){
                pendingNodes.push(front->left);
                }
                if(front->right!=NULL){
                pendingNodes.push(front->right);
                }
               
            }
         
        }
        
        return finalAns;
    }
};