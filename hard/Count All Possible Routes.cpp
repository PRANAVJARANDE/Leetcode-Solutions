class Solution {
public:

    int n;
    const int MOD=1e9+7;
    int helper(int in,int f,int en,vector<int>&a,vector<vector<int>>&dp)
    {
        if(f<0)return 0;
        if(dp[in][f]!=-1)return dp[in][f];
        int ans=0;
        if(in==en)ans++;
        for(int j=0;j<n;j++)
        {
            if(in!=j)
            {
                int res=helper(j,f-abs(a[in]-a[j]),en,a,dp)%MOD;
                ans=((ans%MOD)+(res%MOD))%MOD;
            }
        }
        return dp[in][f]=ans;
    }

    int countRoutes(vector<int>& a, int st, int fi, int fuel) 
    {
        n=a.size();
        vector<vector<int>>dp(n,vector<int>(fuel+1,-1));
        int ans=helper(st,fuel,fi,a,dp);
        return ans;
    }
};
