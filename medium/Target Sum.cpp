class Solution {
public:
    int n;
    int helper(int i,vector<int>&nums,int t,vector<map<int,int>>&dp)
    {    
        if(i>=n)
        {
            if(t==0)return 1;
            else return 0;
        }
        if(dp[i].find(t)!=dp[i].end())return dp[i][t];
        int op1=helper(i+1,nums,t-nums[i],dp);
        int op2=helper(i+1,nums,t+nums[i],dp);
        return dp[i][t]=op1+op2;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        vector<map<int,int>>dp(n);
        int ans=helper(0,nums,target,dp);
        return ans;
    }
};
