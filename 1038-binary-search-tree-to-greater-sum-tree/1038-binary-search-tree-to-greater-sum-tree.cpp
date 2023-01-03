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
    int runningSum=0;
    void inorderTraversal(TreeNode* root){
        if(root==NULL){
            return;
        }
        // reverse inorder,
        inorderTraversal(root->right);
        root->val = root->val + runningSum;
        runningSum= root->val;
        inorderTraversal(root->left);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        inorderTraversal(root);
        return root;
    }
    
};