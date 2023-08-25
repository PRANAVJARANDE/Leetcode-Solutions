class Solution {
public:

    int m,n;
    int helper(int i,int j,vector<vector<int>>&arr,vector<vector<int>>&dp)
    {
        if(i>=m || j>=n || arr[i][j]==1)
        {
            return 0;
        }
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        return dp[i][j]=helper(i+1,j,arr,dp)+helper(i,j+1,arr,dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& arr) 
    {
        m=arr.size(),n=arr[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(0,0,arr,dp);
    }
};
