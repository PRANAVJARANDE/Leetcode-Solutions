class Solution {
public:

    vector<vector<int>> ans;
    void dfs(int in,vector<int>&vis,vector<vector<int>>&adj,int time,int par,vector<int>&move)
    {
        vis[in]=1;
        move[in]=time;
        for(int x:adj[in])
        {
            if(x==par)continue;
            else if(vis[x]==1)
            {
               move[in]=min(move[in],move[x]); 
            }
            else
            {
                dfs(x,vis,adj,time+1,in,move);
                move[in]=min(move[in],move[x]);
                if(move[x]>time)
                {
                    ans.push_back({in,x});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& cn) {
        vector<vector<int>>adj(n);
        for(auto x:cn)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(n,0);
        vector<int> move(n,0);
        dfs(0,vis,adj,0,-1,move);
        return ans;

    }
};
