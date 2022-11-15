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
        if(root==NULL){
            return ans;
        }
        
        string rootData = to_string(root->val);
        
        //check leaf
        if(root->left==NULL && root->right==NULL){
            
            ans.push_back(rootData);
        }
        
        if(root->right!=NULL){
            
            vector<string> rightAns = binaryTreePaths(root->right);
            
            
            for(int i=0;i<rightAns.size();i++){
                
                string currentAns = rootData+"->"+rightAns[i];
                ans.push_back(currentAns);
            }
            
        }
        
        if(root->left!=NULL){
            
            vector<string> leftAns = binaryTreePaths(root->left);
            
            
            for(int i=0;i<leftAns.size();i++){
                
                string currentAns = rootData+"->"+leftAns[i];
                ans.push_back(currentAns);
            }
            
        }
        
        
        return ans;
    }
    
};
