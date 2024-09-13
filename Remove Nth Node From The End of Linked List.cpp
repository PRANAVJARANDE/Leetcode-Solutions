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

   

    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int l=lengthh(head);
        int k=l-n;
        if(n==l)
        {
            return head->next;
        }

        ListNode* temp=head;
        int h=1;
        while(h<k && temp!=NULL)
        {
            temp=temp->next;
            h++;
        }
        if(n==1)
        {
            temp->next=NULL;
            return head;
        }

        temp->next=temp->next->next;

        return head;
    }
};
