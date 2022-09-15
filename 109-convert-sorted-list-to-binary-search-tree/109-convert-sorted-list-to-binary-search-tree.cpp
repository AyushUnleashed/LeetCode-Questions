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
        
        return constructTree(sortedList);
        
        
    }
    
    TreeNode* constructTree(vector<int> sortedList){
        int size = sortedList.size();
        if(size==0){
          return NULL;  
        } 
        
        int midIndex = (int)(size/2);
        int midValue = sortedList[midIndex];
        
        TreeNode* node = new TreeNode(midValue);
        
        vector<int> leftList; 
        
//         for(i=0;i<midIndex;i++){
//             leftList.push_back(sortedList[i]);
//         }
//         for(i=midIndex)
        
        leftList.assign(sortedList.begin(),sortedList.begin()+midIndex);
        vector<int> rightList; 
        rightList.assign(sortedList.begin()+midIndex+1,sortedList.end());
        
        node->left = constructTree(leftList);
        node->right = constructTree(rightList);
        return node;
    }
    
    
};