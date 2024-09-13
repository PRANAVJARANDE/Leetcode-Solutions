class Solution {
public:

    void dfs(int k,vector<bool>&vis,vector<vector<int>> arr,int n)
    {
        vector<int> ts=arr[k];
        for(int i=0;i<n;i++)
        {
            if(ts[i]==1)
            {
                if(vis[i]==0)
                {
                    vis[i]=1;
                    dfs(i,vis,arr,n);
                }
            }
        }
    }


    int findCircleNum(vector<vector<int>>& arr) 
    {
        int n=arr.size();
        vector<bool> vis(n,0);

        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                ans++;
                vis[i]=1;
                dfs(i,vis,arr,n);
            }
        }
        return ans;
    }
};
