class TreeAncestor {
public:

    vector<vector<int>>dp;
    void helper(int in,int par,vector<vector<int>>&adj)
    {
        dp[in][0]=par;
        for(int i=1;i<20;i++)if(dp[in][i-1]!=-1)dp[in][i]=dp[dp[in][i-1]][i-1];
        for(auto x:adj[in])if(x!=par)helper(x,in,adj); 
    }

    TreeAncestor(int n,vector<int>& par) 
    {
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++)
        {
            adj[i].push_back(par[i]);
            adj[par[i]].push_back(i);
        }
        dp=vector<vector<int>>(n,vector<int>(20,-1));
        helper(0,-1,adj);    
    }
    
    int getKthAncestor(int in, int k) 
    {
        for(int i=19;i>=0;i--)
        {
            if(k & (1<<i))
            {
                in=dp[in][i];
                if(in==-1)return -1;
            }
        }
        return in;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
