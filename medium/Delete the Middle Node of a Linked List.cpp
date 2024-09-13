class Solution {
public:
    
    ListNode* deleteMiddle(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }
        
        ListNode* s=head;
        ListNode* f=head;

        while(f!=NULL && f->next!=NULL)
        {
            f=f->next->next;
            s=s->next;
        }

        
        if(s->next!=NULL)
        {
            swap(s->val,s->next->val);
        }
        else
        {
            head->next=NULL;
            delete s;
            return head;
        }

        ListNode* todel=s->next;
        s->next=s->next->next;
        delete todel;
        return head;
    }
};
