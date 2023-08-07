class Solution {
public:

    int n,m;
    void dfs(vector<vector<char>> &arr,int i,int j,vector<vector<int>>&vis)
    {
        if(i<0 || j<0 || i>=m || j>=n)
        {
            return;
        }
        if(vis[i][j]==1 || arr[i][j]=='0')
        {
            return;
        }
        vis[i][j]=1;
        dfs(arr,i+1,j,vis);
        dfs(arr,i-1,j,vis);
        dfs(arr,i,j-1,vis);
        dfs(arr,i,j+1,vis);
    }


    int numIslands(vector<vector<char>>& arr) 
    {
        m=arr.size();
        n=arr[0].size();
        int ans=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==0 && arr[i][j]=='1')
                {
                    dfs(arr,i,j,vis);
                    ans++;
                }
            }
        }
        return ans;
        
    }
};
