class Solution {
public:
    
        class node
        {
            public:
            int slen;
            int sind;
            node* next[26];
            node()
            {
                for(int i=0;i<26;i++)
                {
                    next[i]=NULL;
                    slen=INT_MAX;
                    sind=INT_MAX;
                }
            }
        };
        

        void insertt(node* temp,string s,int in)
        {
            int l=s.size();
            reverse(s.begin(),s.end());

            int i=0;
            while(i<l)
            {
                if(temp->next[s[i]-'a']==NULL)
                {
                    temp->next[s[i]-'a']=new node();
                }
                temp=temp->next[s[i]-'a'];
                
                if(l<temp->slen)
                {
                    temp->slen=l;
                    temp->sind=in;
                }
                i++;
            }
        }

        int searchh(node* temp,string s)
        {
            int l=s.size();
            reverse(s.begin(),s.end());
            for(int i=0;i<l;i++)
            {
                if(temp->next[s[i]-'a']!=NULL)
                {
                    temp=temp->next[s[i]-'a'];
                }
                else
                {
                    break;
                }
            }
            return temp->sind;
        }

    

    vector<int> stringIndices(vector<string>& con, vector<string>& que) 
    {
        node* temp=new node();
        for(int i=0;i<con.size();i++)
        {
            if(con[i].size() < temp->slen)
            {
                temp->slen=con[i].size();
                temp->sind=i;
            }
            insertt(temp,con[i],i);
        }
        int m=que.size();
        vector<int> ans(m,0);
        for(int i=0;i<m;i++)
        {
            ans[i]=searchh(temp,que[i]);
        }
        return ans;
    }
};
