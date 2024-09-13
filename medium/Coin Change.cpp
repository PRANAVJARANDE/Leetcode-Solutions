class Solution {
public:

    int helper(vector<int>& coins, int a,int in,vector<vector<int>> &dp)
    {
        if(a==0)
        {
            return 0;
        }
        if(in==0)
        {
            return INT_MAX-1;
        }

        if(dp[in][a]!=-1)
        {
            return dp[in][a];
        }

        
        if(coins[in-1]>a)
        {
            int donottake= helper(coins,a,in-1,dp);
            dp[in][a]=donottake;
        }
        else
        {
            int take=1+helper(coins,a-coins[in-1],in,dp);
            int dntake=helper(coins,a,in-1,dp);
            dp[in][a]=min(take,dntake);
        }
        return dp[in][a];
    }


    int coinChange(vector<int>& coins, int amount) 
    {
        vector<vector<int>> dp(13,vector<int>(10001,-1));
        int r=helper(coins,amount,coins.size(),dp);
        if(r==INT_MAX-1)
        {
            return -1;
        }
        return r;
    }
};
