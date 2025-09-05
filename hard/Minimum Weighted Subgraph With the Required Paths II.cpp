class Solution {
public:

    void helper(int in,int par,int l,int&cst,vector<int>&psum,vector<int>&depth,vector<vector<int>>&dp,vector<vector<vector<int>>>&adj)
    {
        depth[in]=l;
        dp[in][0]=par;
        for(int i=1;i<21;i++)if(dp[in][i-1]!=-1)dp[in][i]=dp[dp[in][i-1]][i-1];
        psum[in]=cst;
        for(auto x:adj[in])
        {
            if(x[0]!=par)
            {
                cst+=x[1];
                helper(x[0],in,l+1,cst,psum,depth,dp,adj);
                cst-=x[1];
            }
        }
    }

    int find_lca(int a,int b,vector<int>&depth,vector<vector<int>>&dp)
    {
        if(depth[a]>depth[b])swap(a,b);
        int diff=abs(depth[a]-depth[b]);

        for(int i=20;i>=0;i--)if(diff & (1<<i))b=dp[b][i];
        if(a==b)return a;
        for(int i=20;i>=0;i--) 
        {
            if(dp[a][i]!=dp[b][i]) 
            {
                a=dp[a][i];
                b=dp[b][i];
            }
        }
        return dp[a][0];
    }

    int getdis(int a,int b,vector<int>&psum,vector<int>&depth,vector<vector<int>>&dp)
    {
        int L=find_lca(a,b,depth,dp);
        return psum[a]+psum[b]-2*psum[L];
    }

    vector<int> minimumWeight(vector<vector<int>>& edg, vector<vector<int>>& q) 
    {
        int n=edg.size()+1;
        vector<vector<vector<int>>>adj(n);
        for(auto x:edg)
        {
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        vector<int>psum(n,0),depth(n,0);
        vector<vector<int>>dp(n,vector<int>(21,-1));
        int cst=0;
        helper(0,-1,0,cst,psum,depth,dp,adj);

        vector<int>ans;
        for(auto x:q)
        {   
            int s1=x[0],s2=x[1],d=x[2];
            int res=getdis(s1,d,psum,depth,dp)+getdis(s2,d,psum,depth,dp)+getdis(s1,s2,psum,depth,dp);
            res/=2;
            ans.push_back(res);
        }
        return ans;
    }
};
