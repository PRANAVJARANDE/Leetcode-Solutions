class Solution {
public:

    int find_heights(int in,int par,vector<vector<int>>&adj,vector<int>&h1,vector<int>&h2)
    {
        int m1=0,m2=0;
        for(auto x:adj[in])
        {
            if(x!=par)
            {
                int h=find_heights(x,in,adj,h1,h2);
                if(h>=m1)
                {
                    m2=m1;
                    m1=h;
                }
                else if(h>=m2)
                {
                    m2=h;
                }
            }
        }
        h1[in]=m1;
        h2[in]=m2;
        return m1+1;
    }

    map<int,int>m;
    void dfs(int in,int par,int ex,vector<vector<int>>&adj,vector<int>&h1,vector<int>&h2)
    {
        m[in]=max(ex,h1[in]);
        for(auto x:adj[in])
        {
            if(x!=par)
            {
                if(h1[x]+1==h1[in])
                {
                    //pass h2
                    dfs(x,in,max(ex+1,h2[in]+1),adj,h1,h2);
                }
                else
                {
                    //pass h1
                    dfs(x,in,max(ex+1,h1[in]+1),adj,h1,h2);
                }
            }
        }
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(n);
        for(auto x:edges)
        {
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>h1(n,0);
        vector<int>h2(n,0);
        find_heights(0,-1,adj,h1,h2);
        dfs(0,-1,0,adj,h1,h2);
        int mini=INT_MAX;
        for(auto x:m)
        {
            mini=min(mini,x.second);
        }
        vector<int>ans;
        for(auto x:m)
        {
            if(x.second==mini)
            {
                ans.push_back(x.first);
            }
        }
        return ans;
        
    }
};
