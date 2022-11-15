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

    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return NULL;
        
        vector<TreeNode*> pNodes =getPath(root,p->val);
        vector<TreeNode*> qNodes =getPath(root,q->val);
        
        int i=0; TreeNode* lcaNode=NULL;
        while(i<pNodes.size() && i<qNodes.size()&& (pNodes[i]->val==qNodes[i]->val)){
            lcaNode=pNodes[i];
            i++;
        }
        
        return lcaNode;
            
    }
    
    
    //returns true if node is found else return false;
    bool helper(TreeNode* root,vector<TreeNode*> &finalAns,int B){

        if(root==NULL){
            return false;
        }

        finalAns.push_back(root);

        if(root->val==B){
            return true;
        }

        bool leftAns = helper(root->left,finalAns,B);
        bool rightAns = helper(root->right,finalAns,B);

        if(leftAns || rightAns){

            //finalAns.push_back(root->val);
            return true;
        }

        // both left & right are false
        finalAns.pop_back();
        return false;
    }
    
    vector<TreeNode*> getPath(TreeNode* A, int B) {
        vector<TreeNode*> finalAns;
        if(A==NULL) return finalAns;

        bool ans = helper(A,finalAns,B);
        return finalAns;
    }
    
};






























//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
//         if(root==NULL){
//             return NULL;
//         }
        
//         if(root->val==p->val || root->val==q->val){
//             return root;
//         }
        
//         TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
//         TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);
        
//         if(leftAns==NULL && rightAns==NULL){
//             return NULL;
//         }else  if(leftAns!=NULL && rightAns!=NULL){
//             return root;
//         }else  if(leftAns!=NULL && rightAns==NULL){
//             return leftAns;
//         }else  if(leftAns==NULL && rightAns!=NULL){
//             return rightAns;
//         }
        
//         return NULL;
//     }