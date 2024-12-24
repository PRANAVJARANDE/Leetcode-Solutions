class Solution {
public:

    int calh(int in,int par,int &ans,vector<vector<int>>&adj)
    {
        int m1=0,m2=0;
        for(auto x:adj[in])
        {
            if(x!=par)
            {
                int ta=calh(x,in,ans,adj);
                if(ta>m1)
                {
                    m2=m1;
                    m1=ta;
                }
                else if(ta>m2)
                {
                    m2=ta;
                }
            }
        }
        ans=max(ans,m1+m2);
        return m1+1;
    }

    int helper(vector<vector<int>>&e)
    {
        int n=e.size()+1;
        vector<vector<int>>adj(n);
        for(auto x:e)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int ans=0;
        calh(0,-1,ans,adj);
        return ans;
    }


    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int h1=helper(edges1);
        int h2=helper(edges2);
        int ans=max(h1,h2);
        h1=(h1+1)/2;
        h2=(h2+1)/2;
        ans=max(ans,h1+h2+1);
        return ans;
    }
};
