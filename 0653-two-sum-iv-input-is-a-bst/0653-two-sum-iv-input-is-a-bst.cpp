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
    
    bool isNodePresent(int key,TreeNode* root){
        if(root==NULL) return false;
        
        if(key==root->val){
            return true;
        }
        
        return ( isNodePresent(key,root->left) || isNodePresent(key,root->right) );
    }
    
    
    bool helper(TreeNode* currRoot,int k, TreeNode* root){
        
        if(currRoot==NULL || root==NULL){
            return false;
        }
        
        int first = currRoot->val;
        int second = k -first;
        
        bool isSecondPresent;
        if(first!=second){
           isSecondPresent = isNodePresent(second,root);
        }else{
             isSecondPresent = false;
        }
        
        
        if(isSecondPresent==true){
            return true;
        }else{
            
            bool leftAns = helper(currRoot->left,k,root);
            bool rightAns = helper(currRoot->right,k,root);
            
            if(leftAns==true || rightAns==true ){
                return true;
            }
        }
        
        return false;
    }
    
    bool findTarget(TreeNode* root, int k) {
        bool ans =helper(root,k,root);
        return ans;
    }
};