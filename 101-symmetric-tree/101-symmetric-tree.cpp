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
    bool isSymmetric(TreeNode* root) {
        
        return traverse(root,root);
    }
    
    bool traverse(TreeNode* leftRoot,TreeNode* rightRoot){
        
        if(leftRoot==NULL && rightRoot==NULL){
            return true;
        }else if(leftRoot==NULL){
            return false;
        }else if(rightRoot==NULL){
            return false;
        }
        
        bool ans1=false;
        if(leftRoot->val == rightRoot->val)
        {
            ans1=true;
        }
            
        bool ans2= traverse(leftRoot->left,rightRoot->right);
        bool ans3=traverse(leftRoot->right,rightRoot->left);
        
        if(ans1 && ans2 && ans3){
            return true;
        }else{
            return false;
        }
    }
};