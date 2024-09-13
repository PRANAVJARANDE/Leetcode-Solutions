class Solution {
public:
    void reorderList(ListNode* head) 
    {
        deque<int> q1;
        ListNode* temp=head;

        while(temp!=NULL)
        {
            q1.push_back(temp->val);
            temp=temp->next;
        }

        bool b=0;
        temp=head;
        while(temp!=NULL)
        {
            if(b==0)
            {
                b=1;
                temp->val=q1.front();
                q1.pop_front();
            }
            else
            {
                b=0;
                temp->val=q1.back();
                q1.pop_back();
            }
            temp=temp->next;
        }
    }
};
