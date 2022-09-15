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
#include<algorithm>
#include <utility>

class Solution {
public:
    
    bool isBSTHelper(TreeNode *root,long min,long max){
    if(root==NULL) return true;

    if( root->val<=min || root->val >=max){
        return false;
    }
    
    bool ans1 = isBSTHelper(root->left,min,root->val);
    bool ans2 = isBSTHelper(root->right,root->val,max);
      
    return ans1&&ans2;
}

    
    bool isValidBST(TreeNode* root) {
        return isBSTHelper(root,LONG_MIN,LONG_MAX);
    }
    
};