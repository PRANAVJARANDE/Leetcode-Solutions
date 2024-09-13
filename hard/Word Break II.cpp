class Solution {
public:

    class node
    {
        public:
        bool endd;
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
    node *trie;
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
            i++;
        }
        temp->endd=1;
    }

    bool searchh(string s)
    {
        int i=0;
        node* temp=trie;
        while(i<s.size() && temp!=NULL)
        {
            temp=temp->next[s[i]-'a'];
            i++;
        }
        return temp != NULL && temp->endd;
    }

    int n;
    vector<string> ans;
    vector<string> temp;
    void helper(int in,string s,int prev)
    {
        if(in==n)
        {
            if(prev==n-1)
            {
                string d="";
                for(auto m: temp)
                {
                    d=d+" "+m;
                }
                ans.push_back(d.substr(1));
            }
            return;
        }

        string curr=s.substr(prev+1,in-prev);
        if(searchh(curr))
        {
            temp.push_back(curr);
            helper(in+1,s,in);
            temp.pop_back();
        }
        helper(in+1,s,prev);
    }

    vector<string> wordBreak(string s, vector<string>& w) 
    {
        n=s.size();
        trie=new node();
        for(string x: w)
        {
            insertt(x);
        }
        helper(0,s,-1);
        return ans;
    }
};
