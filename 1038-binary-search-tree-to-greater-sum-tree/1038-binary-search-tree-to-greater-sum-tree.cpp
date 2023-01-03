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
    
    
    vector<int> createInorder(TreeNode* root){
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        //left
        ans = createInorder(root->left);
        //root
        ans.push_back(root->val);
        //right
        vector<int> rightAns = createInorder(root->right);
        ans.insert(ans.end(),rightAns.begin(),rightAns.end());
        return ans;
    }
    
    // TreeNode* modifyTraversal(TreeNode* root, unordered_map<int,int> hashMap){
    //     //inorder traversal
    //     //left
    //     if(root==NULL) {
    //         return NULL;
    //     }
    //     TreeNode* leftSubTree = modifyTraversal(root->left,hashMap);
    //     TreeNode* newRoot = new TreeNode(hashMap[root->val]);
    //     TreeNode* rightSubTree = modifyTraversal(root->right,hashMap);        
    //     newRoot->left = leftSubTree;
    //     newRoot->right = rightSubTree;
    //     return newRoot;
    // }
    
    void modifyTraversal(TreeNode*& root, unordered_map<int,int>& hashMap){                       
        //inorder traversal
        //left
        if(root==NULL) {
            return;
        }
        modifyTraversal(root->left,hashMap);
        root->val = hashMap[root->val];
        modifyTraversal(root->right,hashMap);        
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        
        vector<int> inorder = createInorder(root);   
        // modify inorder
        
        int len= inorder.size();
        int runningSum=0;
        unordered_map<int,int> hashMap;
        
        for(int i=len-1;i>=0;i--){
            runningSum+=inorder[i];
            hashMap[inorder[i]]=runningSum;
        }
        
        modifyTraversal(root,hashMap);
        return root;
    }
    
};