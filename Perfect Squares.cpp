class Solution {
public:

    int helper(int n,vector<int> &dp)
    {
        if(n==0)
        {
            return 0;
        }

        if(dp[n]!=INT_MAX)
        {
            return dp[n];
        }
        for(int i=1;i*i<=n;i++)
        {
            dp[n]=min(dp[n],1+helper(n-i*i,dp));
        }
        return dp[n];
    }

    int numSquares(int n) 
    {
        vector<int> dp(10000,INT_MAX);
        return helper(n,dp);
    }
};
