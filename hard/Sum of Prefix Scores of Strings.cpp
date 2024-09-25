class Solution {
public:

    class node
    {
        public:
        int endd;
        node* next[26];
        node()
        {
            endd=0;
            for(int i=0;i<26;i++)
            {
                next[i]=NULL;
            }
        }
    };
    
    void insertt(string s)
    {
        int i=0;
        node* temp=trie;
        while(i<s.size())
        {
            if(temp->next[s[i]-'a']==NULL)
            {
                temp->next[s[i]-'a']=new node();
            }
            temp=temp->next[s[i]-'a'];
            temp->endd++;
            i++;
        }
        
    }
    node* trie;
    int searchh(string s)
    {
        int i=0;
        node* temp=trie;
        int cnt=0;
        while(i<s.size() && temp!=NULL)
        {
            temp=temp->next[s[i]-'a'];
            cnt+=temp->endd;
            i++;
        }
        return cnt;
    }

    vector<int> sumPrefixScores(vector<string>& a) {
        trie=new node();
        for(auto x: a)
        {
            insertt(x);
        }
        int n=a.size();
        vector<int> ans(n,0);
        int in=0;
        for(auto y:a)
        {
            ans[in++]=searchh(y);
        }
        return ans;
    }
};
