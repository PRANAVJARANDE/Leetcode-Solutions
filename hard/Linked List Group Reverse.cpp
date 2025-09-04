class Solution 
{
  public:

    Node *reverseKGroup(Node *head, int k) 
    {
        if(k==1)return head;
    
        vector<int>v1;
        Node* temp=head;
        while(temp)
        {
            v1.push_back(temp->data);
            temp=temp->next;
        }
        
        int sz=v1.size();
        vector<int>vis(sz,0);
        
        int in=k;
        temp=head;
        int cnt=sz;
        
        while(cnt>0)
        {
            //cout<<in<<endl;
            int c=in-1;
            while(c>=0 && vis[c]==0)
            {
                cnt--;
                vis[c]=1;
                temp->data=v1[c];
                temp=temp->next;
                //cout<<v1[c]<<" ";
                c--;
            }
            in+=k;
            in=min(sz,in);
        }
        return head;
    }
};
