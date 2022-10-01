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
    
    int minimumOfBST(TreeNode* root){
        
        if(root==NULL){
            return INT_MAX;
        }
        
        while(root->left!=NULL){
            root=root->left;
        }
        
        return root->val;
    }
    
    
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 1 root==NULL return NULL
        //2  key< root , LeftSide , modify left and reattach, return root
        //3  root<key , right side , modify right and reattach, return root
        
        //4 root == key , need to delete  current root
        // 4a root->left==NULL && root->right == NULL  return NULL
        // 4b root->left==NULL || root->right == NULL  return the side which is not null
        // 4c root->left!=NULL && root->right!= NULL
        /* we find a replacement for root
         maximum of leftSubtree or minimum of right subtree can replace the root
        
        we find maximum of leftsubtree, 
        replace it with root, 
        delete the max for leftsubtree
        
        return the new root
        */
        
        
        if(root==NULL) return NULL; // if key doesn't exist this will eventually occur
        
        if(key<root->val){
            //leftside
            root->left = deleteNode(root->left,key);
            return root;
        }else if(root->val<key){
            //right side
            root->right = deleteNode(root->right,key);
            return root;
        }else if(root->val==key){
            //4
            
            
            
            
            if(root->left==NULL && root->right==NULL){
                return NULL;
            }else if(root->left==NULL && root->right!=NULL){
                return root->right;
            }else if(root->left!=NULL && root->right==NULL){
                return root->left;
            }else if(root->left!=NULL && root->right!=NULL){
                
                //last case
                int rightMin = minimumOfBST(root->right);
                root->val = rightMin;
                root->right = deleteNode(root->right,rightMin);
                
                return root;
                
            }
            
        }
        
        cout<<"This should not happen";
        return NULL;
    }
};