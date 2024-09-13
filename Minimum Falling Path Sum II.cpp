class Solution {
public:

    int n;
    int helper(int i,int j,vector<vector<int>>&arr,vector<vector<int>>&dp)
    {
        if(j>=n || j<0)return INT_MAX;
        if(i==n-1)return arr[i][j];
    
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int h=0;h<n;h++)
        {
            if(h!=j)
            {
                ans=min(ans,arr[i][j]+helper(i+1,h,arr,dp));
            }
        }
        return dp[i][j]=ans;
    }

    int minFallingPathSum(vector<vector<int>>& arr) 
    {
        n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,helper(0,i,arr,dp));
        }
        return ans;
    }
};
