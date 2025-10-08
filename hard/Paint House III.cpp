#define ll long long
class Solution {
public:

    const ll INF=1e15;
    ll helper(ll in,ll pv,ll tar,vector<int>&a,vector<vector<int>>&cst,ll n,ll m,vector<vector<vector<ll>>>&dp)
    {
        if(tar<0)return INF;
        if(in>=m)
        {
            if(tar==0)return 0;
            return INF;
        }
        if(dp[in][pv][tar]!=-1)return dp[in][pv][tar];
        if(a[in]!=0)
        {
            ll ntar=tar;
            if(a[in]!=pv)ntar--;
            return dp[in][pv][tar]=helper(in+1,a[in],ntar,a,cst,n,m,dp);
        }
        ll ans=INF;
        for(int i=0;i<n;i++)
        {
            int ntar=tar;
            if(i+1!=pv)ntar--;
            ll res=cst[in][i]+helper(in+1,i+1,ntar,a,cst,n,m,dp);
            ans=min(ans,res);
        }
        return dp[in][pv][tar]=ans;
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cst, int m, int n, int target)
    {
        vector<vector<vector<ll>>>dp(m,vector<vector<ll>>(n+2,vector<ll>(target+1,-1)));
        ll ans=INF;
        if(houses[0]!=0)ans=helper(1,houses[0],target-1,houses,cst,n,m,dp);
        else
        {
            for(int i=0;i<n;i++)
            {
                ll res=cst[0][i]+helper(1,i+1,target-1,houses,cst,n,m,dp);
                ans=min(ans,res);
            }
        }
        if(ans==INF)ans=-1;
        return ans;
    }
};
