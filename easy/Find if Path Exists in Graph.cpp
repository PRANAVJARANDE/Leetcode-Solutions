class Solution {
public:

    bool dfss(int a,int b,vector<int>v1[],vector<bool> &vis)
    {
        vector<int> ts=v1[a];
        vis[a]=1;
        for(int i=0;i<ts.size();i++)
        {
            if(vis[ts[i]]==0)
            {
                vis[ts[i]]=1;
                if(ts[i]==b)
                {
                    return 1;
                }
                if(dfss(ts[i],b,v1,vis))
                {
                    return 1;
                }
            }
        }
        return 0;
    }



    bool validPath(int n, vector<vector<int>> &e, int a, int b) 
    {
        if(a==b)
        {
            return 1;
        }
        vector<int> v1[n];
        for(int i=0;i<e.size();i++)
        {
            v1[e[i][0]].push_back(e[i][1]);
            v1[e[i][1]].push_back(e[i][0]);
        }

        vector<bool>vis(n,0);

        return dfss(a,b,v1,vis);
    }
};
