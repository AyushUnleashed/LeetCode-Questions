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
    


ListNode *merge(ListNode *head1, ListNode *head2){
    if(head1 == NULL && head2 == NULL){
        return NULL;
    }
    else if(head1 != NULL && head2 != NULL){
        ListNode* newHead = NULL;
        ListNode* newTail = NULL;
        
        while(head1 != NULL && head2 != NULL){
        	ListNode* newNode = NULL;
            if(head1 -> val < head2->val){
                newNode = head1;
            	head1 = head1 -> next;
            }
            else{
                newNode = head2;
            	head2 = head2 -> next;
            }
            if(newHead == NULL){
                newHead = newNode;
                newTail = newNode;
            }
            else{
                newTail -> next = newNode;
                newTail = newNode;
            }
        }
        if(head1 == NULL){
            newTail -> next = head2;
        }
        else{
            newTail -> next = head1;
        }
        return newHead;
    }
    else{
        if(head1 == NULL){
            return head2;
        }
        else{
            return head1;
        }
    }
}


ListNode *midPoint(ListNode *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    
    ListNode* slow;
    ListNode* fast;

    slow = head;
    fast = head->next;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow= slow->next;
        fast = fast->next->next;
    }

    return slow;
}



ListNode *mergeSort(ListNode *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    ListNode* middle = midPoint(head);
    

    
    ListNode* middleNext = middle->next;
    middle->next = NULL;
    
    ListNode* firstSorted = mergeSort(head);
    ListNode* secondSorted = mergeSort(middleNext);
    
    ListNode *ans = merge(firstSorted,secondSorted);
    return ans;
    
}




    
    ListNode* sortList(ListNode* head) {
        
    head =mergeSort(head);
    return head;
    }
};