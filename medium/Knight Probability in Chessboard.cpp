class Solution {
public:
    vector<int>dx={-2,-2,2,2,1,1,-1,-1};
    vector<int>dy={-1,1,-1,1,2,-2,2,-2};
    double helper(int i,int j,int n,int k,vector<vector<vector<double>>>&dp)
    {
        if(i<0 || j<0 || i>=n || j>=n)
        {
            return 0;
        }
        if(k==0)
        {
            return 1;
        }

        if(dp[i][j][k]!=-1)
            return dp[i][j][k];

        double s=0;
        for(int z=0;z<8;z++)
        {
            int nx=i+dx[z];
            int ny=j+dy[z];
            s+=helper(nx,ny,n,k-1,dp);
        }
        return dp[i][j][k]=s/8.0;
    }

    double knightProbability(int n, int k, int row, int column) 
    {
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        return helper(row,column,n,k,dp);
    }
};
