class Solution {
public:

    int n,m;
    bool check(int i,int j,vector<string>&a)
    {
        for(auto x:a)if(x[i]>x[j])return 0;
        return 1;
    }

    int helper(int in,vector<string>&a,vector<int>&dp)
    {
        if(dp[in]!=-1)return dp[in];
        int ans=1;
        for(int j=in+1;j<m;j++)
        {
            if(check(in,j,a))
            {
                int res=1+helper(j,a,dp);
                ans=max(ans,res);
            }
        }
        return dp[in]=ans;
    }

    int minDeletionSize(vector<string>& a) 
    {
        n=a.size();
        m=a[0].size();
        vector<int>dp(m,-1);
        int res=1;
        for(int i=0;i<m;i++)
        {
            res=max(res,helper(i,a,dp));
        }
        return m-res;
    }
};
