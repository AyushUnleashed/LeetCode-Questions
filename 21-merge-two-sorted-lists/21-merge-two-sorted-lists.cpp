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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
       // find minimum of lenght of list 1 and list 2
        
        //length of LL
        
        ListNode* head3=NULL;
        ListNode* tail3=NULL;
        
        ListNode* head1=list1;
        ListNode* head2=list2;
        
        if(head1==NULL && head2==NULL)
        {
            return NULL;
        }
        else if(head1==NULL)
        {
            return head2;
        }
        else if(head2==NULL)
        {
            return head1;
        }
        

        
        
        while(head1!=NULL && head2!=NULL)
        {
            // traverse LL and find minimum element
            
            ListNode* newNode;
            if(head1->val < head2->val)
            {
                newNode= head1;
                head1=head1->next;
            }
            else{
                newNode=head2;
                head2=head2->next;
            }
            
            if(head3==NULL)
            {
                head3=newNode;
                tail3=newNode;
            }else
            {
                tail3->next=newNode;
                tail3=tail3->next;
            }
        }
        
        while(head2!=NULL)
        {
            tail3->next = head2;
            head2=head2->next;
            tail3=tail3->next;
        }
        while(head1!=NULL)
        {
            tail3->next = head1;
            head1=head1->next;
            tail3=tail3->next;
        }
        
        // connect them to head3
        // in end copy rest of the elements to main linkedlist
        
        return head3;
        
    }
    
    int sizeOfLL(ListNode *list)
    {
        int len=0;
        ListNode* temp = list;
        while(temp!=NULL)
        {
            temp=temp->next;
            len++;
        }
        
        return len;
    }
    
};