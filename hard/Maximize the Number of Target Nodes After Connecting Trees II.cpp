class Solution {
public:

    int ev,od;
    vector<int> parity;
    void helper(int in,int l,int par,vector<vector<int>>&adj)
    {
        if(l%2==0)ev++;
        else od++;
        parity[in]=l%2;
        for(auto x:adj[in])
            if(x!=par)helper(x,l+1,in,adj);
    
    }

    vector<int> maxTargetNodes(vector<vector<int>>& e1, vector<vector<int>>& e2) 
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

        ev=0;
        od=0;
        parity=vector<int>(m,0);
        helper(0,0,-1,adj2);
        int ans=max(ev,od);
        
        ev=0;
        od=0;
        parity=vector<int>(n,0);
        helper(0,0,-1,adj1);

        vector<int>res(n,0);
        for(int i=0;i<n;i++)
        {
            res[i]=ans;
            if(parity[i]==0)res[i]+=ev;
            else res[i]+=od;
        }
        return res;
    }
};
