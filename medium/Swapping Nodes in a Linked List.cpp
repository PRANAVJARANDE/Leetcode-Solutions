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


    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* temp=head;
        ListNode* t1=head;
        int l=lengthh(head);
        if(l==1)
        {
            return head;
        }
        
        for(int i=1;i<k;i++)
        {
            temp=temp->next;
        }

        int ln=l-k+1;
        for(int i=1;i<ln;i++)
        {
            t1=t1->next;
        }
        swap(t1->val,temp->val);
        return head;
    }
};
