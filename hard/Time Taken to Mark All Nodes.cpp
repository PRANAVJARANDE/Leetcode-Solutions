class Solution {
public:

    int helper(int in,int par,vector<int>&psum,vector<vector<int>>&adj)
    {
        int maxi=0;
        for(auto x:adj[in])
        {
            if(x!=par)
            {   
                int ta=1+helper(x,in,psum,adj);
                if(x%2==0)ta++;
                maxi=max(maxi,ta);
            }
        }
        return psum[in]=maxi;
    }


    void getans(int in,int par,int extra,vector<int>&psum,vector<int>&res,vector<vector<int>>&adj)
    {
        res[in]=max(psum[in],extra);
        int m1=0,m2=0;
        for(auto x:adj[in])
        {
            if(x!=par)
            {
                int ta=psum[x]+1;
                if(x%2==0)ta++;
                if(ta>=m1)
                {
                    m2=m1;
                    m1=ta;
                }
                else if(ta>=m2)
                {
                    m2=ta;
                }
            }
        }

        //if(in==0)cout<<m1<<" "<<m2<<endl;

        for(auto x:adj[in])
        {
            if(x!=par)
            {
                int ta=1+psum[x];
                if(x%2==0)ta++;
                int nextra=1;
                if(in%2==0)nextra++;
                if(ta==m1)nextra+=max(extra,m2);
                else nextra+=max(extra,m1);
                getans(x,in,nextra,psum,res,adj);
            }
        }
    }

    vector<int> timeTaken(vector<vector<int>>& edges) 
    {
        int n=edges.size()+1;
        vector<vector<int>>adj(n);
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int>psum(n);
        helper(0,-1,psum,adj);

        // for(auto x:psum)cout<<x<<" ";
        // cout<<endl;

        vector<int>ans(n,0);
        getans(0,-1,0,psum,ans,adj);
        return ans;
    }
};
