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



    ListNode* middleNode(ListNode* head) 
    {
        
        int k=lengthh(head)/2;
        int u=0;
        ListNode*temp=head;
        while(u<k)
        {
            temp=temp->next;
            u++;
        }
        return temp;
    }
};
