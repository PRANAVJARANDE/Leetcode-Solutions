class Solution {
public:

    int n;
    const int MOD=1e9+7;
    int helper(int in,int d,int f,vector<int>&dp)
    {   
        if(in>=n)return 0;
        if(dp[in]!=-1)return dp[in];
        int ans=0;
        if(in+f>n-1)ans++;
        for(int j=in+d;j<min(n,in+f);j++)
        {
            ans=((ans%MOD)+(helper(j,d,f,dp)%MOD))%MOD;
        }
        return dp[in]=ans;
    }

    int peopleAwareOfSecret(int nn, int d, int f) 
    {
        n=nn;
        vector<int>dp(n+1,-1);
        return helper(0,d,f,dp);
    }
};
