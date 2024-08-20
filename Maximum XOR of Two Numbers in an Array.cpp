class Solution {
public:
   
    class node
    {
        public:
        bool endd;
        node* next[2];
        node()
        {
            endd=0;
            for(int i=0;i<2;i++)
            {
                next[i]=NULL;
            }
        }
    };
    node* trie;
    
    void insertt(int n)
    {
        node* temp=trie;
        for(int i=31;i>=0;i--)
        {
            int bit=(n>>i) & 1;
            if(temp->next[bit]==NULL)
            {
                temp->next[bit]=new node();
            }
            temp=temp->next[bit];
        }
        temp->endd=1;
    }

    int help(int n)
    {
        int ans=0;
        node* temp=trie;
        for(int i=31;i>=0;i--)
        {
            int bit=(n>>i) & 1;
            if(bit==1)
            {
                if(temp->next[0])
                {
                    temp=temp->next[0];
                    ans=(ans | (1<<i));
                }
                else
                {
                    temp=temp->next[1];
                }
            }
            else
            {
                if(temp->next[1])
                {
                    temp=temp->next[1];
                    ans=(ans | (1<<i));
                }
                else
                {
                    temp=temp->next[0];
                }
            }
        }
        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {
        trie=new node();
        for(int x: nums)insertt(x);
        int ans=0;
        for(int x: nums)ans=max(ans,help(x));
        return ans;

    }
};
