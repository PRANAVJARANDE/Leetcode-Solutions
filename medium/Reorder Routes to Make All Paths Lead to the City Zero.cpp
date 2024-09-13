class Solution {
public:

    void dfs(int k,vector<int> arr[],vector<bool> &vis,int &ans)
    {
        vis[k]=1;
        vector<int> ts=arr[k];
        for(int i=0;i<ts.size();i++)
        {
            if(vis[abs(ts[i])]==0)
            {
                if(ts[i]>0)
                {
                    ans++;
                }
                dfs(abs(ts[i]),arr,vis,ans);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) 
    {
        vector<int> arr[n];
        vector<bool> vis(n,0);
        for(auto x: connections)
        {
            arr[x[0]].push_back(x[1]);
            arr[x[1]].push_back(-x[0]);
        }
        int ans=0;
        dfs(0,arr,vis,ans);
        return ans;
        
    }
};
