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

    int in;
    int helper(ListNode* head)
    {
        if(head==NULL)return 0;
        int ans=helper(head->next);

        int res=(1<<in)*(head->val);
        in++;
        ans+=res;
        return ans;
    }


    int getDecimalValue(ListNode* head) 
    {
        in=0;
        return helper(head);   
    }
};
