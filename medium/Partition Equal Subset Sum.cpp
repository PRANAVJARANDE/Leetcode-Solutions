class Solution {
public:

    int n,s;
    bool helper(vector<int>&nums,int in,int lsum,vector<vector<int>>&dp)
    {
        if(in>=n)
        {
            int s1=s-lsum;
            int s2=lsum;
            if(s1==s2)
            {
                return 1;
            }
            return 0;
        }
        if(dp[in][lsum]!=-1)
        {
            return dp[in][lsum];
        }

        bool take=helper(nums,in+1,lsum-nums[in],dp);
        bool ntake=helper(nums,in+1,lsum,dp);
        return dp[in][lsum]=take || ntake;
    }

    bool canPartition(vector<int>& nums) 
    {
        n=nums.size();
        for(int i=0;i<n;i++)
        {
            s+=nums[i];
        }
        if(s%2==1)
        {
            return 0;
        }
        vector<vector<int>> dp(n,vector<int>(s+1,-1));
        return helper(nums,0,s,dp);   
    }
};
