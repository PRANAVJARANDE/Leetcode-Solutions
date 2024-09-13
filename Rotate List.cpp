/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
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

    ListNode* rotateRight(ListNode* head, int k) 
    {
        int l=lengthh(head);
        if(k==0 || l==0)
        {
            return head;
        }
        
        
        k=k%l;
        int n=l-k;


        ListNode *t=head;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=head;

        int p=1;
        ListNode *temp=head;

        while(p<n)
        {
            temp=temp->next;
            p++;
        }

        head=temp->next;
        temp->next=NULL;

        return head;
    }
};
