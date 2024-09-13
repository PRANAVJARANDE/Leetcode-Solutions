class Solution {
public:

    int n;
    int helper(vector<int>&nums,int t,vector<int>&dp)
    {
        if(t==0)
        {
            return 1;
        }
        if(t<0)
        {
            return 0;
        }

        if(dp[t]!=-1)
            return dp[t];

        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=helper(nums,t-nums[i],dp);
        }
        return dp[t]=ans;
    }

    int combinationSum4(vector<int>& nums, int t) 
    {
        n=nums.size();
        vector<int> dp(t+1,-1);
        return helper(nums,t,dp);
    }
};
