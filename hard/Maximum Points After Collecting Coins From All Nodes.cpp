class Solution {
public:

    int helper(int in,int par,int d,int k,vector<vector<int>>&adj,vector<int>&a,vector<vector<int>>&dp)
    {
        if(d>=16)return 0;
        if(dp[in][d]!=-1)return dp[in][d];
        
        int org=(a[in]/(1<<d));
        int op1=org-k;
        int op2=org/2;
        for(auto x:adj[in])
        {
            if(x!=par)
            {
                op1+=helper(x,in,d,k,adj,a,dp);
                op2+=helper(x,in,d+1,k,adj,a,dp);
            }
        }
        
        return dp[in][d]=max(op1,op2);
    }

    int maximumPoints(vector<vector<int>>& edges, vector<int>& a, int k) 
    {
        int n=a.size();
        vector<vector<int>>adj(n);
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<vector<int>>dp(n,vector<int>(17,-1));
        int ans=helper(0,-1,0,k,adj,a,dp);
        return ans;

        
    }
};
