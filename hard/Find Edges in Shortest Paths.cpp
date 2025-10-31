class Solution {
public:

    map<pair<int,int>,bool>paths;
    void helper(int in,vector<vector<int>>&par,vector<int>&vis)
    {
        if(vis[in]==1)return;
        vis[in]=1;
        for(auto x:par[in])
        {
            paths[{min(x,in),max(x,in)}]=1;
            helper(x,par,vis);
        }
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& e) 
    {
        vector<vector<pair<int,int>>>adj(n);
        for(auto x:e)
        {
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        vector<int>dis(n,INT_MAX);
        vector<vector<int>>par(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q1;
        dis[0]=0;
        q1.push({0,0});
        while(!q1.empty())
        {
            auto cst=q1.top().first;
            auto in=q1.top().second;
            q1.pop();
            if(dis[in]<cst)continue;
            for(auto x:adj[in])
            {
                if(dis[x.first]>cst+x.second)
                {
                    dis[x.first]=cst+x.second;
                    q1.push({dis[x.first],x.first});
                    par[x.first].clear();
                    par[x.first].push_back(in);
                }
                else if(dis[x.first]==cst+x.second)
                {
                    par[x.first].push_back(in);
                }
            }
        }
        int m=e.size();
        vector<bool>ans(m,0);
        vector<int>vis(n,0);
        helper(n-1,par,vis);
        for(int i=0;i<m;i++)if(paths[{min(e[i][0],e[i][1]),max(e[i][0],e[i][1])}]==1)ans[i]=1;
        return ans;
    }
};
