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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* finalHead = NULL;
        ListNode* finalTail=NULL;
        ListNode* temp = finalHead;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto& listPtr: lists){
            ListNode* head = listPtr;
            
            while(head!=NULL){
                pq.push(head->val);
                head = head->next;
            }
            
        }
        
        while(!pq.empty()){
            
            ListNode* newNode = new ListNode(pq.top());
            if(finalHead==NULL && finalTail==NULL){       
                finalHead = newNode;
                finalTail = newNode;
                
            }else{
                finalTail->next= newNode;
                finalTail=finalTail->next;
               
            }
             pq.pop();
        }
        
        return finalHead;
    }
};