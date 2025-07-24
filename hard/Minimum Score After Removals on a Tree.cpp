class Solution {
public:

    int helper(int in,int par,vector<vector<int>>&adj,vector<int>&nums,vector<int>&dp,vector<int>&pr,vector<vector<int>>&st,vector<int>&vis)
    {
        pr[in]=par;
        int xs=nums[in];
        vis[in]=1;
        for(auto x:adj[in])
        {
            if(x!=par)
            {
                xs=xs^helper(x,in,adj,nums,dp,pr,st,vis);
            }
        }
        st[in]=vis;
        vis[in]=0;
        dp[in]=xs;
        return xs;
    }

    int get_child(int p1,int p2,vector<int>&pr)
    {
        if(pr[p1]==p2)return p1;
        return p2;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& e)
    {
        int n=nums.size();
        vector<vector<int>>adj(n);
        for(auto x:e)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int>vis(n,0);
        vector<vector<int>>st(n);
        vector<int>dp(n,0),pr(n,-1);
        int ts=helper(0,-1,adj,nums,dp,pr,st,vis);

        int ans=(1<<30)-1;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                auto e1=e[i];
                int c1=get_child(e1[0],e1[1],pr);
                

                auto e2=e[j];
                int c2=get_child(e2[0],e2[1],pr);

                int x1,x2,x3;
                if(st[c1][c2])
                {
                    x1=dp[c1];
                    x2=dp[c2]^dp[c1];
                    x3=ts^dp[c2];
                }
                else if(st[c2][c1])
                {
                    x1=dp[c2];
                    x2=dp[c1]^dp[c2];
                    x3=ts^dp[c1];
                }
                else
                {
                    x1=dp[c1];
                    x2=dp[c2];
                    x3=ts^x1^x2;
                }
                int maxi=max(x1,max(x2,x3));
                int mini=min(x1,min(x2,x3));
                int res=maxi-mini;
                ans=min(ans,res);
            }
        }
        return ans;   
    }
};
