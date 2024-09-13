class Solution {
public:

    int helper(vector<int>&nums,int in,int n,vector<int>&dp)
    {
        if(in>=n)
        {
            return 0;
        }
        if(dp[in]!=-1)
            return dp[in];
        //rob
        int op1=nums[in]+helper(nums,in+2,n,dp);
        //not rob
        int op2=helper(nums,in+1,n,dp);
        return dp[in]=max(op1,op2);
    }

    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(n,-1);
        int a1=nums[0]+helper(nums,2,n-1,dp);
        vector<int>cdp(n,-1);
        int a2=helper(nums,1,n,cdp);
        return max(a1,a2);
    }
};
