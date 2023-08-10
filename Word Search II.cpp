class Solution {
public:

    class node
    {
        public:
        bool end;
        string word;
        node* next[26];
        node()
        {
            for(int i=0;i<26;i++)
            {
                next[i]=NULL;
            }
            end=0;
            word="";
        }
    };

    node* root=new node();

    void insert(string s)
    {
        int in=0;
        node* temp=root;
        while(in<s.size())
        {
            if(temp->next[s[in]-'a']==NULL)
            {
                temp->next[s[in]-'a']=new node();
            }
            temp=temp->next[s[in]-'a'];
            in++;
        }
        temp->end=1;
        temp->word=s;
    }

    int m,n;
    vector<string> res;
    bool dfs(vector<vector<char>>&b, int i,int j,vector<vector<int>>&vis,node* temp)
    {
        
        if(temp->end)
        {
            temp->end=0;
            res.push_back(temp->word);
        } 
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j]==1 )
        {
            return 0;
        }
        
        temp=temp->next[b[i][j]-'a'];
        if(temp==NULL)
        {
            return 0;
        }
        
        vis[i][j]=1;
        bool b1=dfs(b,i+1,j,vis,temp);
        bool b2=dfs(b,i-1,j,vis,temp);
        bool b3=dfs(b,i,j+1,vis,temp);
        bool b4=dfs(b,i,j-1,vis,temp);
        vis[i][j]=0;
        return b1 || b2|| b3|| b4;
    }

    vector<string> findWords(vector<vector<char>>& b, vector<string>& arr) 
    {
        m=b.size();
        n=b[0].size();
        for(string x: arr)
        {
            insert(x);
        }
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dfs(b,i,j,vis,root);
            }
        }
        
        return res;
    }
};
