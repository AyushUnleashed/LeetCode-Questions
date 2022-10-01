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
    
    /* Method1
    vector<int> inorderTraversal(TreeNode* root) {
            vector<int> ans;
        if(root==NULL) return ans;
        
        vector<int> leftAns= inorderTraversal(root->left);
        ans.insert(ans.end(),leftAns.begin(),leftAns.end());
        
        ans.push_back(root->val);
        
        vector<int> rightAns = inorderTraversal(root->right);
        ans.insert(ans.end(),rightAns.begin(),rightAns.end());
        
        return ans;
    }
    
    TreeNode* inorderToBST(vector<int> sortedList,int start,int end){
        int size = sortedList.size();
        if(start>end){
          return NULL;  
        } 
        
        int midIndex = (start+end)/2;
        int midValue = sortedList[midIndex];
        
        TreeNode* node = new TreeNode(midValue);
        
        node->left = inorderToBST(sortedList,start,midIndex-1);
        node->right = inorderToBST(sortedList,midIndex+1,end);
        return node;
    }
    
    vector<int> insertInSortedArray(vector<int> arr,int val){
        
        arr.push_back(val);
        sort(arr.begin(),arr.end());
        return arr;
    }
    
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        
        vector<int> inorder = inorderTraversal(root);
        inorder = insertInSortedArray(inorder,val);
        TreeNode* ans = inorderToBST(inorder,0,inorder.size()-1);
        
        return ans;
    }

*/
    
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//         //find where the node should be
//         //if it comes out to be null
//         //insert it there
        
//         if(root==NULL){
//             TreeNode* newNode = new TreeNode(val);
//             return newNode;
//         }
        
//         if(val>root->val){
            
//             if(root->right==NULL){
//                 //nothing there, make a node 
//                 TreeNode* newNode = new TreeNode(val);
//                 root->right = newNode;
                
//             }else{
//                 //not null
//                 TreeNode* newNode = insertIntoBST(root->right,val);
//                 root->right = newNode;
//             }
//             return root;
//         }else{
//             //left side
            
//               if(root->left==NULL){
//                 //nothing there, make a node 
//                 TreeNode* newNode = new TreeNode(val);
//                 root->left = newNode;
                
//             }else{
//                 //not null
//                 TreeNode* newNode = insertIntoBST(root->left,val);
//                 root->left = newNode;
//             }
//             return root;
//         }
//     }
    
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
     
        if(root==NULL){
            return new TreeNode(val);
        }
        
        if(val< root->val){
            //left side
            
            if(root->left==NULL){
                TreeNode* newNode = new TreeNode(val);
                root->left = newNode;
            }else{
                TreeNode* newNode =insertIntoBST(root->left,val);
                root->left = newNode;
            }
    
        }else{
            //right side
            
                        
            if(root->right==NULL){
                TreeNode* newNode = new TreeNode(val);
                root->right = newNode;
            }else{
                
                TreeNode* newNode =insertIntoBST(root->right,val);
                root->right = newNode;
            }
        }
        
        return root;
    }
   
};