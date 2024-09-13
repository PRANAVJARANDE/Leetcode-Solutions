class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode* h1=new ListNode(-1);
        ListNode*p1=h1;
        ListNode* h2=new ListNode(-1);
        ListNode*p2=h2;

        ListNode* temp=head;

        while(temp!=NULL)
        {
            if(temp->val < x)
            {
                p1->next=new ListNode(temp->val);
                p1=p1->next;
            }
            else
            {
                p2->next=new ListNode(temp->val);
                p2=p2->next;
            }
            temp=temp->next;
        }


        p1->next=h2->next;
        ListNode* todel=h1;
        h1=h1->next;
        delete todel;

        ListNode* td=h2;
        h2=h2->next;
        delete td;

        
        return h1;
    
    }
};
