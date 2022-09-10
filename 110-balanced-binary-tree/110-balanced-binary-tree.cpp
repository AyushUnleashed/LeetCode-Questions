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

#include<algorithm>
class Solution {
public:
    
    int heightOfBT(TreeNode* root){
        
        if(root==NULL)
            return 0;
        
        return (1 + max(heightOfBT(root->left),heightOfBT(root->right)));
    }
    
    bool isBalanced(TreeNode* root) {
        
        if(root==NULL)
        {
            return true;
        }
        int leftHeight = heightOfBT(root->left);
        int rightHeight = heightOfBT(root->right);
        
        int diff = leftHeight-rightHeight;
        
        if(diff<0){
            diff=-diff;
        }
        
        if(diff>1){
            return false;
        }
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);
        
        if(leftAns==true && rightAns==true){
            return true;
        }
        
        return false;
    }
    
    
};