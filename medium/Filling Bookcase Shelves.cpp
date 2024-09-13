class Solution {
public:

    int n,aw;
    int helper(int in,vector<vector<int>>&a,vector<int>&dp)
    {
        if(in>=n)return 0;
        if(dp[in]!=-1)return dp[in];
        int s=aw;
        int maxi=INT_MIN;
        int ans=INT_MAX;
        for(int i=in;i<n;i++)
        {
            int t=a[i][0];
            int h=a[i][1];
            maxi=max(maxi,h);
            s-=t;
            if(s<0)break;
            ans=min(ans,maxi+helper(i+1,a,dp));
        }
        return dp[in]=ans;
    }

    int minHeightShelves(vector<vector<int>>& a, int w) {
        n=a.size();
        aw=w;
        vector<int>dp(n,-1);
        int ans=helper(0,a,dp);
        return ans;
    }
};
