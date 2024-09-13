class Solution {
public:

    int MOD=1e9+7;
    int helper(int n,int k,int t,vector<vector<int>>&dp)
    {
        if(n==0 && t==0) return 1;
        if(n==0 || t<=0) return 0;

        if(dp[n][t]!=-1) return dp[n][t];

        int c=0;
        for(int i=1;i<=k;i++)
        {
            c=((c%MOD)+(helper(n-1,k,t-i,dp)%MOD))%MOD;
        }
        return dp[n][t]=c;
    }

    int numRollsToTarget(int n, int k, int t) 
    {
        vector<vector<int>>dp(n+1,vector<int>(t+1,-1));
        return helper(n,k,t,dp);
    }
};
