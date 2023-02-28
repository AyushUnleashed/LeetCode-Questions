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
    
    pair<int,ListNode*> sizeOfLL(ListNode* l){
        ListNode* temp = l;
        int count=0;
        ListNode* tail=NULL;
        while(l!=NULL){
            count++;
            tail=l;
            l=l->next;
        }
        return {count,tail};
    }
    
    ListNode* addTwoNumbersHelper(ListNode* l1,ListNode* l2){
        if(l1==NULL || l2==NULL){
            return NULL;
        }    
        int carry=0;
        ListNode* l1Head = l1;
        ListNode* tail1=NULL;
        while(l1!=NULL && l2!=NULL){
            
            int val1 = l1->val;
            int val2 = l2->val;
            int sum = val1 + val2 + carry;
            carry = sum/10;
            int setVal = sum%10;
            l1->val = setVal;
            tail1=l1;
            l1=l1->next;
            l2=l2->next;
        }
        
        if(carry==0){
            return l1Head;
        }else{
            ListNode* newNode = new ListNode(carry);
            tail1->next =newNode;
            tail1=tail1->next;
        }
        return l1Head;
        
    }
        
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL || l2==NULL){
            return NULL;
        }

        //base condn
        pair<int,ListNode*> l1ppt = sizeOfLL(l1);
        pair<int,ListNode*> l2ppt = sizeOfLL(l2);

        int l1Size = l1ppt.first;
        int l2Size = l2ppt.first;
        ListNode* tail1 = l1ppt.second;
        ListNode* tail2 = l2ppt.second;

        int diff = l1Size-l2Size;

        if(diff>0){
            //l1 is bigger
            while(diff>0){
                ListNode* newNode = new ListNode(0);
                tail2->next = newNode;
                tail2=tail2->next;
                diff--;
            }
        }else if(diff<0){
            //l2 is bigger
            diff=-diff;
            while(diff>0){
                ListNode* newNode = new ListNode(0);
                tail1->next = newNode;
                tail1=tail1->next;
                diff--;
            }
        }
        return addTwoNumbersHelper(l1,l2);

    }

};