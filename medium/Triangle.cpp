class Solution {
public:

    int helper(vector<vector<int>>&nums,int i,int j,vector<vector<int>>& dp)    
    {
        if(i>=nums.size())
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        return dp[i][j]=nums[i][j]+min(helper(nums,i+1,j,dp),helper(nums,i+1,j+1,dp));
    }

    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(triangle[n-1].size(),-1));
        return helper(triangle,0,0,dp);
    }
};
