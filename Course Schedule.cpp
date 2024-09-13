class Solution {
public:


    bool ccycle(int k,vector<bool>&vis,vector<bool> &crvis,vector<int> v1[])
    {
        vector<int>ts=v1[k];
        vis[k]=1;
        crvis[k]=1;
        for(int i=0;i<ts.size();i++)
        {
            if(vis[ts[i]]==0)
            {
                if(ccycle(ts[i],vis,crvis,v1))
                {
                    return 1;
                }
            }
            else if(vis[ts[i]]==1 && crvis[ts[i]]==1)
            {
                return 1;
            }
        }
        crvis[k]=0;
        return 0;
    }



    bool canFinish(int n, vector<vector<int>>& pre) 
    {
        vector<int> v1[n];
        for(auto x: pre)
        {
            v1[x[0]].push_back(x[1]);
        }
        vector<bool> vis(n,0),crvis(n,0);

        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                if(ccycle(i,vis,crvis,v1))
                {
                    return 0;
                }
            }
        }
        return 1;
    }
};
