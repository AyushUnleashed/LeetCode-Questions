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
    
    //Inorder Traversal Method
//     int rangeSumBST(TreeNode* root, int low, int high) {
//         if(root==NULL) return 0;
        
//         int sum=0;
        
//         sum+=rangeSumBST(root->left,low,high);
        
//         if(root->val >=low && root->val <=high){
//             sum+=root->val;
//         }
        
//         sum+=rangeSumBST(root->right,low,high);
        
//         return sum;
//     }
    
    // 
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        int sum=0;

        if(root->val > high){
            // range must be on the left side
            //no need to go to right side
            sum+=rangeSumBST(root->left,low,high);
        }
        else if (root->val <low){
            // range sum must be on the right side
            //no need to go the left side
            sum+=rangeSumBST(root->right,low,high);
        }
        else if(root->val>=low && root->val<=high){
            // range belongs to both left and right side
            sum+=rangeSumBST(root->left,low,high);
            sum+=root->val;
            sum+=rangeSumBST(root->right,low,high);
        }
        
        return sum;
    }
    
};