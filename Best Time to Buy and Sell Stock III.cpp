class Solution {
public:
    int n;
    int helper(vector<int>&nums,int in,int b,int k,vector<vector<vector<int>>>&dp)
    {
        if(in>=n || k<=0)
            return 0;
        
        if(dp[in][b][k]!=-1)
            return dp[in][b][k];

        if(b==0)
        {
            int buy=-nums[in]+helper(nums,in+1,1,k,dp);
            int nbuy=helper(nums,in+1,0,k,dp);
            return dp[in][b][k]=max(buy,nbuy);
        }
        else
        {
            int sell=nums[in]+helper(nums,in+1,0,k-1,dp);
            int nsell=helper(nums,in+1,1,k,dp);
            return dp[in][b][k]=max(sell,nsell);
        }
    }

    int maxProfit(vector<int>& nums) 
    {
        n=nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(nums,0,0,2,dp);
    }
};
