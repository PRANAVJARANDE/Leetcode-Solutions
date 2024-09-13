class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode *nh=new ListNode(head->val);
        ListNode *ptr=nh;
        ListNode *temp=head;

        while(temp!=NULL)
        {
            ptr->next=new ListNode(temp->val);
            temp=temp->next;
            ptr=ptr->next;
        }

        ListNode *todel=nh;
        nh=nh->next;
        delete todel;

        ListNode *p1=nh;
        ListNode *p2=nh->next;

        while(p1!=NULL && p2!=NULL)
        {
            swap(p1->val,p2->val);
            p1=p2->next;
            if(p1==NULL)
            {
                break;
            }
            p2=p1->next;
        }
        return nh;
    }
};
