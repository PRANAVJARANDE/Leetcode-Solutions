class Solution {
public:
    ListNode* removeNodes(ListNode* head) 
    {
        vector<int> v1;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            v1.push_back(temp->val);
            temp=temp->next;
        }

        int ma=INT_MIN;
        vector<int> ans;
        for(int i=v1.size()-1;i>=0;i--)
        {
            if(ma<=v1[i])
            {
                ans.push_back(v1[i]);
                ma=v1[i];
            }
        }

        ListNode* nh=new ListNode(-1);
        ListNode* tt=nh;
        for(int i=ans.size()-1;i>=0;i--)
        {
            tt->next=new ListNode(ans[i]);
            tt=tt->next;
        }
        return nh->next;
    }
};

//METHOD 2 BY STACK
class Solution {
public:
    ListNode* removeNodes(ListNode* head) 
    {
        stack<int> s1;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            while(!s1.empty() && s1.top()<temp->val)
            {
                s1.pop();
            }
            s1.push(temp->val);
            temp=temp->next;
        }
        ListNode* nh=NULL;
        while(!s1.empty())
        {
            ListNode* n=new ListNode(s1.top());
            s1.pop();
            
            n->next=nh;
            nh=n;
        }
        return nh;
    }
};
