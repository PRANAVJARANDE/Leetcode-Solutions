class Solution {
public:

    int dest;
    long long helper(vector<int>&nums,int x,int in,vector<vector<long long>> &dp,int prev)
    {
        if(in>=dest)
            return 0;
        
        if(dp[in][prev]!=-1)
            return dp[in][prev];
        
        int jj=nums[in]%2;
        long long take=nums[in]-((prev!=jj)? x : 0 )+helper(nums,x,in+1,dp,jj);
        long long ntake=helper(nums,x,in+1,dp,prev);
        return dp[in][prev]=max(take,ntake);
    }
    long long maxScore(vector<int>& nums, int x) 
    {
        dest=nums.size();
        vector<vector<long long>> dp(dest,vector<long long>(2,-1));
        return nums[0]+helper(nums,x,1,dp,nums[0]%2);
    }
};
