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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;

        ans.push_back(root->val);
        vector<int> leftAns = preorderTraversal(root->left);
        vector<int> rightAns = preorderTraversal(root->right);
        
        ans.insert( ans.end(), leftAns.begin(), leftAns.end() );
        ans.insert( ans.end(), rightAns.begin(), rightAns.end() );
        return ans;
    }
};