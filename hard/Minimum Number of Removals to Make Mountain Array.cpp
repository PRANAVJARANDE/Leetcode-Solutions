class Solution {
public:
    int n;
    int minimumMountainRemovals(vector<int>& a)
    {
        n=a.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(a[prev]<a[i])
                {
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
        }
        vector<int>dp1(n,1);
        for(int i=n-1;i>=0;i--)
        {
            for(int prev=n-1;prev>i;prev--)
            {
                if(a[i]>a[prev])
                {
                    dp1[i]=max(dp1[i],1+dp1[prev]);
                }
            }
        }
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            if(dp[i]>1 && dp1[i]>1)ans=max(ans,dp[i]+dp1[i]-1);
        }
        return n-ans;
    }
};
