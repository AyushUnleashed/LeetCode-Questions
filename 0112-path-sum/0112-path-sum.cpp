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
class Solution{
public:
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL){
           return false; 
        } 
        bool leftCall=false;
        bool rightCall = false;
        
        int rootData = root->val;
        
        if(root->left==NULL && root->right==NULL && rootData==targetSum){
            return true;
        }
        //left call
        if(root->left!=NULL){
            leftCall = hasPathSum(root->left,targetSum-rootData);
        }
        if(root->right!=NULL){
            rightCall = hasPathSum(root->right,targetSum-rootData);
        }
        
        if(leftCall || rightCall){
            return true;
        }else return false;
    }
};