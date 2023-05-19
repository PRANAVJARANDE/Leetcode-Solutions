class Solution {
public:

    int lengthh(ListNode *head)
    {
        int k=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            k++;
            temp=temp->next;
        }
        return k;
    }



    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head==NULL)
        {
            return NULL;
        }

        if(lengthh(head)<k)
        {
            return head;
        }

        ListNode* bptr=NULL;
        ListNode* cptr=head;
        ListNode* fptr;

        int u=0;
        while(cptr!=NULL && u<k)
        {
            fptr=cptr->next;
            cptr->next=bptr;
            bptr=cptr;
            cptr=fptr;
            u++;
        }

        ListNode *nh=bptr;

        head->next=reverseKGroup(cptr,k);
        return nh;
        
    }
};
