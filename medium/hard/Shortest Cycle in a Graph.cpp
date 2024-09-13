class Solution {
public:

    int maxi;
    void dfs(int in,vector<vector<int>>&adj,vector<int>&vis,int k,vector<int>&lev,int par)
    {
        vis[in]=1;
        lev[in]=k+1;
        for(int x:adj[in])
        {
            if(vis[x]==0 || lev[x]>k+1)
            {
                dfs(x,adj,vis,k+1,lev,in);
            }
            else if(vis[x]!=0)
            {
                int z=lev[in]-lev[x];
                if(z>=2)maxi=min(maxi,lev[in]-lev[x]+1);
            }
        }
    }


    int findShortestCycle(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(n);
        for(auto x: edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        maxi=INT_MAX;
        vector<int> vis(n,0);
        vector<int> lev(n,INT_MAX);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,adj,vis,1,lev,-1);
            }
            
        }
        if(maxi==INT_MAX)return -1;
        return maxi;
    }
};
