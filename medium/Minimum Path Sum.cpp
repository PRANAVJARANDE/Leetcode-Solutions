class Solution {
public:
    int minPathSum(vector<vector<int>>& arr) 
    {
        int m=arr.size();
        int n=arr[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=arr[0][0];
        for(int i=1;i<m;i++)
        {
            dp[i][0]=arr[i][0]+dp[i-1][0];
        }
        for(int j=1;j<n;j++)
        {
            dp[0][j]=arr[0][j]+dp[0][j-1];
        }

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=arr[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};

class Solution {
public:

    int helper(vector<vector<int>>& arr,int i,int j,vector<vector<int>> &dp)
    {
        if(i<0 || j<0)
            return INT_MAX;
        
        if(i==0 && j==0)
            return arr[0][0];

        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j]=arr[i][j]+min(helper(arr,i-1,j,dp),helper(arr,i,j-1,dp));
    }

    int minPathSum(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return helper(grid,m-1,n-1,dp);
    }
};
