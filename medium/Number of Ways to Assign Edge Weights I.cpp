#define ll long long
class Solution {
public:

    ll mod_pow(ll a,ll b, ll m) { 
        ll res=1;
        while(b>0){
            if(b&1){
                res=(res*a)%m;
            }
            a=(a*a)%m;
            b=b>>1;
        }
        return res;
    }

    int helper(int in,int par,vector<vector<int>>&adj)
    {
        int ans=0;
        for(auto x:adj[in])
        {
            if(x!=par)
            {
                int nh=1+helper(x,in,adj);
                ans=max(ans,nh);
            }
        }
        return ans;
    }

    const int MOD=1E9 + 7;
    int assignEdgeWeights(vector<vector<int>>& e) 
    {
        int n=e.size()+1;
        vector<vector<int>>adj(n);
        for(auto x:e)
        {
            x[0]--;
            x[1]--;
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        int h=helper(0,-1,adj);
        cout<<h<<endl;
        ll res=mod_pow(2,h-1,MOD);
        return res;
    }
};
