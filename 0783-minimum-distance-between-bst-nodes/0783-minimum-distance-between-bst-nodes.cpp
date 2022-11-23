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
#include<limits.h>

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        if(root==NULL) return 0;
        
        vector<int> inorder = inorderTraversal(root);
//         for(auto &x:inorder){
//             cout<<x<<" ";
//         }
        
        int minDiff=INT_MAX;
        
        for(int i=0;i<inorder.size()-1;i++){
            
            int diff = inorder[i+1]-inorder[i];
            if(diff<minDiff){
                minDiff=diff;
            }
        }
        
        return minDiff;
    }
    
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> leftAns;
        if(root==NULL){
            return leftAns;
        }
        //left
        leftAns = inorderTraversal(root->left);
        
        //current
        leftAns.push_back(root->val);
        
        //right
        vector<int> rightAns= inorderTraversal(root->right);
        
        for(auto &x:rightAns){
            leftAns.push_back(x);
        }
        
        return leftAns;
        
    }
};