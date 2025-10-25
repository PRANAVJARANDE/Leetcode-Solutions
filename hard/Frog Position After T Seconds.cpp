class Solution {
public:

    double ans;
    int time,tar;
    bool helper(int in,int par,int l,double prob,vector<vector<int>>&adj)
    {
        if(l>time)return 0;

        int ch=adj[in].size();
        if(par!=-1)ch--;

        if(in==tar)
        {
            if(l==time || ch==0)ans=prob;
            return 1;
        }
        
        for(auto x:adj[in])
        {
            if(x!=par)
            {
                if(helper(x,in,l+1,prob/ch,adj))return 1;
            }
        }
        return 0;
    }

    double frogPosition(int n, vector<vector<int>>& edges, int tm, int target) 
    {
        vector<vector<int>>adj(n);
        for(auto x:edges)
        {
            adj[x[0]-1].push_back(x[1]-1);
            adj[x[1]-1].push_back(x[0]-1);
        }
        ans=0.0;
        tar=target-1;
        time=tm;
        helper(0,-1,0,1.0,adj);
        return ans;
    }
};
