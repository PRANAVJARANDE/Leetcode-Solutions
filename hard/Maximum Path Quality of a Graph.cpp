class Solution {
public: 

    int ans;
    void helper(int in,int time,int maxi,vector<int>&val,vector<int>&vis,vector<vector<pair<int,int>>>&adj,int curr)
    {   
        if(time>maxi)return;

        if(vis[in]==0)curr+=val[in];
        vis[in]++;

        if(in==0)ans=max(ans,curr);

        for(auto x:adj[in])
        {
            helper(x.first,time+x.second,maxi,val,vis,adj,curr);
        }

        vis[in]--;
    }

    int maximalPathQuality(vector<int>& val, vector<vector<int>>& edges, int maxTime) 
    {
        int n=val.size();
        ans=0;

        vector<vector<pair<int,int>>>adj(n);
        for(auto x:edges)
        {
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }

        vector<int>vis(n,0);
        helper(0,0,maxTime,val,vis,adj,0);
        return ans;
    }
};
