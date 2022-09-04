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
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        // if both nodes on different sides
        int ans1 = getHeight(root->left)+getHeight(root->right);
        int ans2 = diameterOfBinaryTree(root->left);
        int ans3 = diameterOfBinaryTree(root->right);

        return max(max(ans1,ans2),ans3);
    }
    
    int getHeight(TreeNode* root){

    if(root==NULL){
        return 0;
    }

    int lHeight = getHeight(root->left);
    int rHeight = getHeight(root->right);

    return max(lHeight,rHeight)+1;
    }

};