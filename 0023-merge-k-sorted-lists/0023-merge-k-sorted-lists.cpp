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

    class Node{
        public:
        ListNode* node;
        int i;
        
        Node(ListNode* node,int i){
            this->node=node;
            this->i=i;
        }
    };
    
    class Compare{
        public:
        bool operator()(Node a,Node b){
            if(a.node->val > b.node->val){
                return true;
            }else{
                return false;
            }
        }
    };

        
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int k=lists.size();
        if(k==0){
            return NULL;
        }
        
        ListNode* mergedHead=NULL;
        ListNode* mergedTail=NULL;
        
        priority_queue<Node,vector<Node>, Compare> pq;
      //build heap from first elements of all lists
        
        vector<ListNode*> ptr(k);
        
        for(int i=0;i<k;i++){
            ptr[i]=lists[i];
            if(ptr[i]!=NULL)
            {
                pq.push(Node(ptr[i],i));
            }
        }
        
        if(pq.empty()){
            return NULL;
        }
        
                
        // add first element to final merged list
        mergedHead = pq.top().node;
        mergedTail = pq.top().node;
    
        int index = pq.top().i;
        pq.pop();
        
        ptr[index]=ptr[index]->next;

        if(ptr[index]!=NULL){
           pq.push(Node(ptr[index],index));
        }

        
        while(!pq.empty()){
           
            int index = pq.top().i;
            ListNode* temp = pq.top().node;
            pq.pop();
        
            mergedTail->next = temp;
            mergedTail=mergedTail->next;
            
            ptr[index]=ptr[index]->next;
            
            if(ptr[index]!=NULL){
                pq.push(Node(ptr[index],index));
            }
        }
        
        return mergedHead;
        
    }
};