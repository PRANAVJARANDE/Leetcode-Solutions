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
    set<int>s1;
    ListNode* helper(ListNode* head)
    {
        if(head==NULL)
        {
            return head;
        }
        ListNode* nxt=helper(head->next);
        if(s1.find(head->val)!=s1.end())
        {
            return nxt;
        }
        head->next=nxt;
        return head;
    }

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        for(int x: nums)s1.insert(x);
        return helper(head);
    }
};
