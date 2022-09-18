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
#include<string>  
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root==NULL) return ans;
        
        if(root->left==NULL && root->right==NULL){
            //leaf node
            string rootData = to_string(root->val);
            ans.push_back(rootData);
            return ans;
        }
        
        if(root->left!=NULL){
            vector<string> leftAns= binaryTreePaths(root->left);
            
            for(auto& str:leftAns){
                string newStr = to_string(root->val)+"->"+str;
                ans.push_back(newStr);
            }
            
        }
        
        if(root->right!=NULL){
            vector<string> rightAns= binaryTreePaths(root->right);
            
            for(auto& str:rightAns){
                string newStr = to_string(root->val)+"->"+str;
                ans.push_back(newStr);
            }
        }
        
        return ans;
    }
};
