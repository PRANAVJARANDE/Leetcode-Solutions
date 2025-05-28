class Solution {
public:

    int helper(int in,int l,int par,vector<vector<int>>&adj)
    {
        if(l<0)return 0;
        int res=1;
        for(auto x:adj[in])
            if(x!=par)res+=helper(x,l-1,in,adj);
    
        return res;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& e1, vector<vector<int>>& e2, int k) 
    {
        int n=e1.size()+1;
        int m=e2.size()+1;
        vector<vector<int>>adj2(m),adj1(n);
        for(auto x:e2)
        {
            adj2[x[0]].push_back(x[1]);
            adj2[x[1]].push_back(x[0]);
        }
        for(auto x:e1)
        {
            adj1[x[0]].push_back(x[1]);
            adj1[x[1]].push_back(x[0]);
        }

        int ans=0;
        for(int i=0;i<m;i++)ans=max(ans,helper(i,k-1,-1,adj2));
        
        vector<int>res(n,0);
        for(int i=0;i<n;i++)
        {
            res[i]=ans+helper(i,k,-1,adj1);
        }
        return res;
    }
};
