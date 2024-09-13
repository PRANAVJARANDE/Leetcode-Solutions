#define ll long long
class Solution {
public:

    vector<ll> dfs(int in,vector<vector<int>>&adj,vector<int>&cost,int par,vector<ll>&ans)
    {
        vector<ll> a1;
        for(int x:adj[in])
        {
            if(x!=par)
            {
                auto y=dfs(x,adj,cost,in,ans);
                for(ll t:y)
                {
                    a1.push_back(t);
                }
            }
        }
        a1.push_back(cost[in]);
        if(a1.size()<3)return a1;
        sort(a1.begin(),a1.end());
        int hj=a1.size();
        ll p1=a1[hj-1];
        ll p2=a1[hj-2];
        ll p3=a1[hj-3];
        ll n1=a1[0];
        ll n2=a1[1];
        ans[in]=max(0ll,p1*max(p2*p3,n1*n2));
        if(hj<5)return a1;
        return {n1,n2,p3,p2,p1};
    }

    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n=cost.size();
        vector<vector<int>>adj(n);
        for(auto x: edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<long long> ans(n,1);
        dfs(0,adj,cost,-1,ans);
        return ans;
    }
};
