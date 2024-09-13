class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode* temp=head;
        ListNode* fptr=head;
        ListNode* sptr=head;
        while(fptr!=NULL && fptr->next!=NULL && fptr->next->next!=NULL)
        {
            fptr=fptr->next->next;
            sptr=sptr->next;
            if(fptr==sptr)
            {
                fptr=head;
                while(fptr!=sptr)
                {
                    fptr=fptr->next;
                    sptr=sptr->next;
                }
                return fptr;
            }
        }
        return NULL;
    }
};
