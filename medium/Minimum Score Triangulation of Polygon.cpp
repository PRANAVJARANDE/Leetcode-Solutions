class Solution {
public:

    int helper(int i,int j,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(i+1==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int z=i+1;z<j;z++)
        {
            ans=min(ans,arr[i]*arr[j]*arr[z]+helper(i,z,arr,dp)+helper(z,j,arr,dp));
        }
        return dp[i][j]=ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(0,n-1,values,dp);
    }
};
