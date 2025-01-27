class Solution {
public:

    bool dfs(int in,vector<vector<int>>&adj,vector<int>&vis,int tar)
    {
        if(in==tar)return 1;
        for(auto x:adj[in])
        {
            if(vis[x]==0)
            {
                vis[x]=1;
                bool res=dfs(x,adj,vis,tar);
                if(res==1)return 1;
            }
        }
        return 0;
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& q) {
        vector<vector<int>>adj(n);
        for(auto x:p)adj[x[0]].push_back(x[1]);
        
        vector<bool>ans;
        for(auto x:q)
        {
            int s=x[0];
            int e=x[1];
            vector<int>vis(n,0);
            vis[s]=1;
            bool res=dfs(s,adj,vis,e);
            ans.push_back(res);
        }
        return ans;
    }
};
