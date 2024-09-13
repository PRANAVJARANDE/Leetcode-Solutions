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

    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        int l=lengthh(head);
        int j=l/k;
        vector<int> v1(k,j);
        int rem=l%k;
        for(int i=0;i<rem;i++)
        {
            v1[i]++;
        }

        vector<ListNode*> ans;
        for(int i=0;i<k;i++)
        {
            int count=v1[i];
            if(count==0)
            {
                ans.push_back(NULL);
                continue;
            }
            ListNode* temp=head;
            for(int i=1;i<count;i++)
            {
                temp=temp->next;
            }
            
            ListNode* t1=temp->next;
            temp->next=NULL;
            ans.push_back(head);
            head=t1;
        }
        return ans;
    }
};
