class Solution 
{
public:
    int m,n;
    vector<int>dx{1,-1,0,0};
    vector<int>dy{0,0,1,-1};
    int helper(vector<vector<int>>&arr,int i,int j,vector<vector<bool>>&vis)
    {
        if(i<0 || j< 0 || i>=m || j>=n || vis[i][j]==1 || arr[i][j]==0)
            return 0;

        vis[i][j]=1;
        int ans=arr[i][j];
        for(int k=0;k<4;k++)
        {
            int nx=i+dx[k];
            int ny=j+dy[k];
            ans+=helper(arr,nx,ny,vis);
        }
        return ans;
    }


    int findMaxFish(vector<vector<int>>& arr) 
    {
        m=arr.size();
        n=arr[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=max(ans,helper(arr,i,j,vis));
            }
        }
        return ans;
    }
};
