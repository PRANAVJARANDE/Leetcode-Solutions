class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(n),m(n,vector<int>(n,0));
        for(auto &x:edges)
        {
            x[0]--;
            x[1]--;
            m[x[0]][x[1]]=1;
            m[x[1]][x[0]]=1;
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int ans=INT_MAX;
        for(auto x:edges)
        {
            int u=x[0],v=x[1];
            for(auto w:adj[u])
            {
                if(w!=v && w!=u && m[u][w] && m[w][v])
                {
                    int res=adj[u].size()+adj[v].size()+adj[w].size()-6;
                    ans=min(ans,res); 
                }
            }
        }
        // int ans=INT_MAX;
        // for(int i=0;i<n;i++)
        // {
        //     for(auto x:adj[i])
        //     {
        //         for(auto y:adj[i])
        //         {
        //             if(x!=y && m[{min(x,y),max(x,y)}]==1)
        //             {
        //                 int res=adj[x].size()+adj[y].size()+adj[i].size()-6;
        //                 ans=min(ans,res);      
        //             }
        //         }
        //     }
        // }
        if(ans==INT_MAX)ans=-1;
        return ans;
    }
};
