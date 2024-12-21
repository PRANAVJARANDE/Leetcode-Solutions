class Solution {
public:

    int ans;
    long long helper(int in,int par,int k,vector<int>&val,vector<vector<int>>&adj)
    {
        long long s=val[in];
        for(int x:adj[in])
        {
            if(x!=par)
            {
                s+=helper(x,in,k,val,adj);
            }
        }
        if(s%k==0)
        {
            ans++;
            return 0;
        }
        return s;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& e, vector<int>& v, int k) 
    {
        vector<vector<int>>adj(n);
        for(auto x:e)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        ans=0;
        helper(0,-1,k,v,adj);
        return ans;
    }
};
