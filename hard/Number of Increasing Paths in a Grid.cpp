class Solution {
public:

    const int MOD=1e9 +7;
    int m,n;
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};

    bool issafe(int i,int j)
    {
        return i>=0 && j>=0 && i<m && j<n;
    }

    int helper(vector<vector<int>>&arr,int i,int j,vector<vector<int>>&dp)
    {
        if(i<0 || j<0 || i>=m || j>=n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];

        int s=1;
        for(int k=0;k<4;k++)
        {
            int nx=i+dx[k];
            int ny=j+dy[k];
            
            if(issafe(nx,ny) && arr[nx][ny]>arr[i][j])
            {
                s=(s%MOD + helper(arr,nx,ny,dp) %MOD) %MOD;
            }
        }
        return dp[i][j]=s;
    }

    int countPaths(vector<vector<int>>& arr) {
        int ans=0;
        m=arr.size();
        n=arr[0].size();
        vector<vector<int>>dp (m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=(ans%MOD+helper(arr,i,j,dp)%MOD)%MOD;
            }
        }
        return ans;
    }
};
