class Solution {
public:
    int n;
    bool helper(int in,vector<int>&nums,int k,vector<vector<int>>&dp)
    {
        if(in==n-1)
            return 1;

        if(dp[in][k]!=-1)
            return dp[in][k];

        bool op1=0;
        for(int i=in+1;i<n;i++)
        {
            if(nums[i]-nums[in]>k+1)
                break;
            else if(nums[i]-nums[in]==k-1)
            {
                op1|=helper(i,nums,k-1,dp);
            }
            else if(nums[i]-nums[in]==k)
            {
                op1|=helper(i,nums,k,dp);
            }
            else if(nums[i]-nums[in]==k+1)
            {
                op1|=helper(i,nums,k+1,dp);
            }
        }
        return dp[in][k]= op1;
    }

    bool canCross(vector<int>& nums) {
        n=nums.size();
        if(nums[1]-nums[0]>1)
        {
            return 0;
        }
        if(n==2)
        {
            return nums[1]-nums[0]==1 ;
        }
        vector<vector<int>>dp(n,vector<int>(4000,-1));
        return helper(0,nums,0,dp);
    }
};
