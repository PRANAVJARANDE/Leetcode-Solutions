class Solution {
public:

    void dfs(int in,int par,vector<int>&freq,vector<vector<vector<int>>>&adj,vector<vector<int>>&ans)
    {
        ans[in]=freq;
        for(auto &x:adj[in])
        {
            if(x[0]!=par)
            {
                freq[x[1]]++;
                dfs(x[0],in,freq,adj,ans);
                freq[x[1]]--;
            }
        }
    }

    void helper(int in,int par,int l,vector<int>&parent,vector<int>&depth,vector<vector<vector<int>>>&adj,vector<vector<int>>&dp)
    {
        dp[in][0]=par;
        depth[in]=l;
        parent[in]=par;
        for(int i=1;i<21;i++)if(dp[in][i-1]!=-1)dp[in][i]=dp[dp[in][i-1]][i-1];
        for(auto x:adj[in])if(x[0]!=par)helper(x[0],in,l+1,parent,depth,adj,dp);
    }

    int find_lca(int a,int b,vector<int>&depth,vector<vector<int>>&dp)
    {
        if(depth[a]>depth[b])swap(a,b);
        int diff=abs(depth[a]-depth[b]);

        for(int i=20;i>=0;i--)if(diff & (1<<i))b=dp[b][i];
        if(a==b)return a;
        for(int i=20;i>=0;i--) 
        {
            if(dp[a][i]!=-1 && dp[a][i]!=dp[b][i]) 
            {
                a=dp[a][i];
                b=dp[b][i];
            }
        }
        return dp[a][0];
    }

    vector<int> minOperationsQueries(int n, vector<vector<int>>& edg, vector<vector<int>>& q) 
    {
        vector<vector<vector<int>>>adj(n);
        for(auto x:edg)
        {
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        vector<vector<int>>dp(n,vector<int>(21,-1));
        vector<int>depth(n,0);
        vector<int>parent(n,0);
        helper(0,-1,0,parent,depth,adj,dp);

        vector<vector<int>>ans(n);
        vector<int>freq(27,0);
        dfs(0,-1,freq,adj,ans);


        vector<int>res;
        for(auto x:q)
        {
            if(x[0]==x[1])res.push_back(0);
            else 
            {
                int l=find_lca(x[0],x[1],depth,dp);
                vector<int>t1=ans[x[0]];
                vector<int>t2=ans[x[1]];
                vector<int>t3=ans[l];
                int dis=0;
                int maxi=0;
                for(int i=0;i<27;i++)
                {
                    int yt=t1[i]+t2[i]-2*t3[i];
                    dis+=yt;
                    maxi=max(maxi,yt);
                }
                res.push_back(dis-maxi);
            }
        }
        return res;
    }
};
