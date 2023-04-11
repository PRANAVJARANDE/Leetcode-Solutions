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

    bool isPalindrome(ListNode* head)
    {
        int l=lengthh(head)/2;
        vector<int> v1;
        ListNode* temp=head;

        for(int i=0;i<l;i++)
        {
            v1.push_back(temp->val);
            temp=temp->next;
        }

        if(lengthh(head)%2==1)
        {
            temp=temp->next;
        }

        int u=l-1;
        while(temp!=NULL)
        {
            if(temp->val!=v1[u])
            {
                return 0;
            }
            temp=temp->next;
            u--;
        }

    return 1;

    }
};
