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
    
    vector<int> convertToInorder(TreeNode* root){
        
        vector<int> finalAns;
        if(root==NULL){
            return finalAns;
        }
        
       
        vector<int> leftAns= convertToInorder(root->left);
        
        for(int i=0;i<leftAns.size();i++){
            finalAns.push_back(leftAns[i]);
        }
        
        finalAns.push_back(root->val);
        
        vector<int> rightAns = convertToInorder(root->right);
        
        for(int i=0;i<rightAns.size();i++){
            finalAns.push_back(rightAns[i]);
        }
        
        return finalAns;
        
    }
        
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder = convertToInorder(root);
        
        //Two Sum; first + second =k  // key, value -> val,index
        
        unordered_map<int,int> map;
        
        for(int i=0;i<inorder.size();i++){
            
            int first = inorder[i];
            int second = k - first;
            
            if(map.find(second)!=map.end()){
                //we found the second element
                return true;
            }
            
            map[first]=i;
        }
        
        return false;
    }
    
};