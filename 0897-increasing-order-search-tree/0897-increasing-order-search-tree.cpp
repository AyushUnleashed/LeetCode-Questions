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
    TreeNode* increasingBST(TreeNode* root) {
        
        if(root==NULL){
            return root;
        }
        
    
        //left
        TreeNode* leftAns = increasingBST(root->left);
        //right
        TreeNode* rightAns = increasingBST(root->right);
        //current
        
        if(leftAns!=NULL){
            
            TreeNode* temp=leftAns;
        
            while(temp->right!=NULL){
                temp=temp->right;
            }
            temp->right = root;
            
            root->right = rightAns;
            root->left=NULL;
            
            return leftAns;
        }else{
            root->left=NULL;
            root->right = rightAns;
            return root;
            
        }
        
        return NULL;
        
    }
};