class Solution {
public:

    int helper(vector<int>&nums,int i,int j,int b,vector<vector<vector<int>>> &dp)
    {
        if(j<=i)
        {
            return 0;
        }

        if(dp[i][j][b]!=-1)
            return dp[i][j][b];

        if(b==0)
        {
            int l1=nums[j]+helper(nums,i,j-1,1,dp);
            int f1=nums[i]+helper(nums,i+1,j,1,dp);
            return dp[i][j][b]=max(l1,f1);
        }
        else
        {
            int l2=nums[i]+helper(nums,i+1,j,0,dp);
            int f2=nums[j]+helper(nums,i,j-1,0,dp);
            return dp[i][j][b]=min(l2,f2);
        }
    }

    bool stoneGame(vector<int>& nums) 
    {
        int s=0;
        for(int x: nums)
        {
            s+=x;
        }
        int n=nums.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        int h=helper(nums,0,n-1,0,dp);
        if(2*h>s)
        {
            return 1;
        }
        return 0;
    }
};
