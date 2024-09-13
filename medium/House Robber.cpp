class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        vector<int> dp(n+1,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};

class Solution {
public:

    int helper(vector<int>&nums,int s,int dest,vector<int>&dp)
    {
        if(s>=dest)
            return 0;
        
        if(dp[s]!=-1)
            return dp[s];

        return dp[s]=max(nums[s]+helper(nums,s+2,dest,dp),helper(nums,s+1,dest,dp));
    }

    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return helper(nums,0,n,dp);
    }
};
