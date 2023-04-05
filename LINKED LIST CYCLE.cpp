class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *s=head;
        ListNode *f=head;

        while(f!=NULL && f->next!=NULL)
        {
            f=f->next->next;
            s=s->next;
            if(f==s)
            {
                return 1;
            }

        }

        return 0;

    }
};
