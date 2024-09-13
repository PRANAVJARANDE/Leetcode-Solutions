class Solution {
public:
    ListNode* insertionSortList(ListNode* head) 
    {
        priority_queue<int,vector<int>,greater<int>> q1;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            q1.push(temp->val);
            temp=temp->next;
        }

        temp=head;
        while(temp!=NULL)
        {
            temp->val=q1.top();
            q1.pop();
            temp=temp->next;
        }
        return head;
    }
};
