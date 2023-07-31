class Solution {
public:

    int helper(vector<int> &nums,int in,int b,int dest,int fee,vector<vector<int>>&dp)
    {
        if(in>=dest)
            return 0;
        
        if(dp[in][b]!=-1)
            return dp[in][b];

        if(b==0)
        {
            return dp[in][b]=max(nums[in]+helper(nums,in+1,1,dest,fee,dp),helper(nums,in+1,0,dest,fee,dp));
        }
        else
        {
            return dp[in][b]=max(-fee-nums[in]+helper(nums,in+1,0,dest,fee,dp),helper(nums,in+1,1,dest,fee,dp));
        }
    }

    int maxProfit(vector<int>& prices, int fee) 
    {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(prices,0,1,n,fee,dp);
    }
};
