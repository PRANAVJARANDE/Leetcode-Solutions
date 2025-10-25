class Solution {
public:

    vector<int>res,lvl;

    void build(int in,int par,int l,vector<vector<int>>&adj)
    {
        lvl[in]=l;
        for(auto x:adj[in])
        {
            if(x!=par)
            {
                build(x,in,l+1,adj);
            }
        }
    }

    vector<vector<int>>m;
    void helper(int in,int par,vector<int>&nums,vector<vector<int>>&adj)
    {
        for(int i=1;i<=50;i++)
        {
            if(!m[i].empty() && (__gcd(i,nums[in]))==1)
            {
                if(res[in]==-1)res[in]=m[i].back();
                else if(lvl[res[in]]<lvl[m[i].back()])res[in]=m[i].back();
            }
        }
        m[nums[in]].push_back(in);
        for(auto x:adj[in])if(x!=par)helper(x,in,nums,adj);
        m[nums[in]].pop_back();
    }

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) 
    {
        int n=nums.size();
        res=vector<int>(n,-1);
        lvl=vector<int>(n,0);
        m=vector<vector<int>>(58);
        vector<vector<int>>adj(n);
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        build(0,-1,0,adj);
        helper(0,-1,nums,adj);
        return res;
    }
};
