class Solution {
public:

    bool check(int mid,int n,vector<vector<vector<int>>>&adj)
    {
        vector<int>vis(n,0);
        vis[0]=1;
        queue<int>q1;
        q1.push(0);
        int cnt=1;
        while(!q1.empty())
        {
            int in=q1.front();
            q1.pop();

            for(auto x:adj[in])
            {
                if(vis[x[0]]==0 && x[1]<=mid)
                {
                    cnt++;
                    vis[x[0]]=1;
                    q1.push(x[0]);
                }
            }
        }

        if(cnt==n)return 1;
        return 0;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int th) 
    {
        vector<vector<vector<int>>>adj(n);
        int l = INT_MAX, r = INT_MIN;
        for(auto x:edges)
        {
            int u=x[0];
            int v=x[1];
            adj[v].push_back({u,x[2]});
            l = min(l, x[2]);
            r = max(r, x[2]);
        }
        if(!check(r,n,adj))return -1;
        int ans=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid,n,adj))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
