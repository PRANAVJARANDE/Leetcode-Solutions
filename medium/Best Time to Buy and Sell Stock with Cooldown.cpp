class Solution {
public:

    int helper(vector<int>&nums,int in,int b,int dest,vector<vector<int>>&dp)
    {
        if(in>=dest)
            return 0;

        if(dp[in][b]!=-1)
            return dp[in][b];

        if(b==0)
        {
            return dp[in][b]=max(nums[in]+helper(nums,in+2,1,dest,dp),helper(nums,in+1,0,dest,dp));
        }
        else
        {
            return dp[in][b]=max(-nums[in]+helper(nums,in+1,0,dest,dp),helper(nums,in+1,1,dest,dp));
        }
    }



    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return helper(prices,0,1,n,dp);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));

        for(int i=n-1;i>=0;i--)
        {
            dp[i][0]=max(nums[i]+dp[i+2][1],dp[i+1][0]);
            dp[i][1]=max(-nums[i]+dp[i+1][0],dp[i+1][1]);
        }
        return dp[0][1];
    }
};
