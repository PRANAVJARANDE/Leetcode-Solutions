class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head==NULL)
        {
            return NULL;
        }
        
        ListNode* temp=head;
        ListNode* nh=new ListNode(head->val);
        if(head->next==NULL)
        {
            return nh;
        }
        ListNode* ptr1=nh;

        while(temp->next!=NULL)
        {
            if(temp->next->val!=temp->val)
            {
                ptr1->next=new ListNode(temp->val);
                ptr1=ptr1->next;
            }
            temp=temp->next;
        }

        if(temp->val!=ptr1->val)
        {
            ptr1->next=new ListNode(temp->val);
        }

        if(nh->next!=NULL && nh->val==nh->next->val)
        {
            nh=nh->next;
        }

        return nh;

    }
};
