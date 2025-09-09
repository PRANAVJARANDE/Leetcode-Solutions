class Solution {
public:

    int n;
    int helper(int in,vector<int>&a,int d,vector<int>&dp)
    {
        int ans=0;
        if(dp[in]!=-1)return dp[in];
        for(int i=in+1;i<min(n,in+d+1);i++)
        {
            if(a[i]>=a[in])break;
            int res=helper(i,a,d,dp);
            ans=max(ans,res);
        }
        for(int i=in-1;i>=max(0,in-d);i--)
        {
            if(a[i]>=a[in])break;
            int res=helper(i,a,d,dp);
            ans=max(ans,res);
        }
        return dp[in]=1+ans;
    }

    int maxJumps(vector<int>& a, int d) 
    {
        n=a.size();
        int ans=1;
        vector<int>dp(n,-1);
        for(int i=0;i<n;i++)
        {
            int res=helper(i,a,d,dp);
            ans=max(ans,res);
        }
        return ans;
    }
};
