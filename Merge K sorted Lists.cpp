class Solution 
{
public:

    ListNode* mergeKLists(vector<ListNode*>& arr) 
    {
    
       priority_queue<int,vector<int>,greater<int>> q1;
       for(int i=0;i<arr.size();i++)
       {
           ListNode* temp=arr[i];
           while(temp!=NULL)
           {
               q1.push(temp->val);
               temp=temp->next;
           }
       }

       if(q1.size()==0)
       {
           return NULL;
       }

        ListNode* nh=new ListNode(q1.top());
        q1.pop();
        ListNode* ptr=nh;
       while(!q1.empty())
       {
           ptr->next=new ListNode(q1.top());
           q1.pop();
           ptr=ptr->next;
       }
       return nh;

        
    }
};
