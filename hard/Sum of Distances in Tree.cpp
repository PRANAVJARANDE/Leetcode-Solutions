class Solution {
public:

    int helper(int in,int par,vector<int>&cst,vector<int>&psum,vector<vector<int>>&adj)
    {
        psum[in]=1;
        cst[in]=0;
        for(auto x:adj[in])
        {
            if(x!=par)
            {
                psum[in]+=helper(x,in,cst,psum,adj);
                cst[in]+=cst[x];
                cst[in]+=psum[x];
            }
        }
        return psum[in];
    }


    void getans(int in,int par,int extra,vector<int>&ans,vector<int>&cst,vector<int>&psum,vector<vector<int>>&adj)
    {
        int n=ans.size();
        ans[in]=cst[in]+extra;

        //cout<<"Hiiee "<<in<<" "<<extra<<endl;

        for(auto x:adj[in])
        {
            if(x!=par)
            {
                int rem=cst[in]-cst[x]-psum[x];
                rem+=n-psum[x];
                getans(x,in,extra+rem,ans,cst,psum,adj);
            }
        }
    }



    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(n);
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<int>cst(n,0);
        vector<int>psum(n,0);

        helper(0,-1,cst,psum,adj);

        vector<int>ans(n,0);
        getans(0,-1,0,ans,cst,psum,adj);

        return ans;
    }
};
