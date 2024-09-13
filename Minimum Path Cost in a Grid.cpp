class Solution {
public:

    int helper(vector<vector<int>>& grid, vector<vector<int>>& moc,int in,int i,int dest,vector<vector<int>> &dp)
    {
        if(in==dest-1)
            return grid[in][i];
    
        if(dp[in][i]!=-1)
            return dp[in][i];

        int ans=INT_MAX;

        for(int j=0;j<grid[in+1].size();j++)
        {
            ans=min(ans,grid[in][i]+moc[grid[in][i]][j]+helper(grid,moc,in+1,j,dest,dp));
        }
        return dp[in][i]=ans;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& mot) 
    {
        int ans=INT_MAX;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<grid[0].size();i++)
        {
            ans=min(ans,helper(grid,mot,0,i,n,dp));
        }
        return ans;
        
    }
};
