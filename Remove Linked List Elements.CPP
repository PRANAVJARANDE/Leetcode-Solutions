class Solution {
public:
    ListNode* removeElements(ListNode* head, int k) 
    {
        if(head==NULL)
        {
            return NULL;
        }        
        ListNode *temp=head;
        while(temp->next!=NULL)
        {
            if(temp->next->val==k)
            {
                ListNode* todel=temp->next;
                temp->next=temp->next->next;
                delete todel;
            }
            else
            {
                temp=temp->next;
            }
        }
        if(head->val==k)
        {
            ListNode* tode=head;
            head=head->next;
            delete tode;
        }
        return head;
    }
};
