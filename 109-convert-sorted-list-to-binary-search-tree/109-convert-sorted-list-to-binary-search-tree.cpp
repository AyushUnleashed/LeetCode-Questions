/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(head==NULL ){
            return NULL;
        }
        
        vector<int> sortedList;
        while(head!=NULL){
            sortedList.push_back(head->val);
            head=head->next;
        }
        
        return inorderToBST(sortedList,0,sortedList.size()-1);
        
        
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
    
    
};