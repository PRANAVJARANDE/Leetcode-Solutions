class Solution {
public:

    int n;
    long long helper(int in,bool col,int k,vector<vector<long long>>&dp,vector<int>& nums)
    {
        if(in>=n)
        {
            if(col==0)return 0;
            else return LLONG_MIN;
        }
        if(dp[in][col]!=-1)return dp[in][col];
        long long op1=(nums[in]^k)+helper(in+1,!col,k,dp,nums);
        long long op2=nums[in]+helper(in+1,col,k,dp,nums);
        return dp[in][col]=max(op1,op2);
    }

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) 
    {
        n=nums.size();
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return helper(0,0,k,dp,nums);
    }
};
