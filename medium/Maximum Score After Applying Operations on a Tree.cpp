class Solution {
public:

    long long dfs(int i,vector<vector<int>>&adj,vector<int>&val,vector<bool>&vis)
    {
        if(adj[i].size()==1 && i!=0)
        {
            return val[i];
        }
        long long s=0;
        vis[i]=1;
        for(auto j: adj[i])
        {
            if(vis[j]==0)
            {
                s=s+dfs(j,adj,val,vis);
            }
        }
        return min((long long)val[i],s);
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& val) 
    {
        int n=val.size();
        vector<vector<int>> adj(n);
        for(auto x: edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        long long s=0;
        for(int x : val)s+=x;

        vector<bool> vis(n,0);
        long long k=dfs(0,adj,val,vis);
        return s-k;
    }
};
