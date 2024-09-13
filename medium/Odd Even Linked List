class Solution 
{
public:
    ListNode* oddEvenList(ListNode* head)
    {
        if(head==NULL)
        {
            return NULL;
        }
            ListNode *odd=head;
            ListNode *eve=head->next;
            ListNode *evehead=eve;
        
        
        while(odd->next!=NULL && eve->next!=NULL)
        {
            eve=odd->next;
            odd->next=eve->next;
            odd=odd->next;
            eve->next=odd->next;
            eve=eve->next;
        }

        odd->next=evehead;

        return head;
    }
};
