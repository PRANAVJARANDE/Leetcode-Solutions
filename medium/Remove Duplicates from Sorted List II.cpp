class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head==NULL)
        {
            return NULL;
        }
        set<int> s1,s2;
        ListNode* temp=head;

        while(temp->next!=NULL)
        {
            if(temp->val==temp->next->val)
            {
                s1.insert(temp->val);
            }
            s2.insert(temp->val);
            temp=temp->next;
        }
        s2.insert(temp->val);


       for(int x: s1)
       {
           s2.erase(x);
       }

        if(s2.empty())
        {
            return NULL;
        }

        queue<int> q1;
        for(int x:s2)
        {
            q1.push(x);
        }

        ListNode* nh=new ListNode(q1.front());
        q1.pop();
        ListNode* ptr=nh;

        while(!q1.empty())
        {
            ptr->next=new ListNode(q1.front());
            ptr=ptr->next;
            q1.pop();
        }

        return nh;
    }
};
