/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        if(original==NULL || cloned==NULL){
            return NULL;
        }
        TreeNode* targetCopy;
        
        if(original==target){
            targetCopy = cloned;
        }else{
            
            TreeNode* leftAns = getTargetCopy(original->left,cloned->left,target);
            TreeNode* rightAns = getTargetCopy(original->right,cloned->right,target);
            
            if(leftAns!=NULL){
                targetCopy = leftAns;
            }else if(rightAns!=NULL){
                targetCopy = rightAns;
            }else{
                targetCopy = NULL;
            }
            
        }
        
        return targetCopy;
    }
};