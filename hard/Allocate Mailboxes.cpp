#define ll long long
class Solution {
public:

    int n;
    const ll INF=1E15;
    ll helper(ll in,ll k,vector<int>&a,vector<vector<int>>&dp)
    {
        if(in>=n)return 0;
        if(k==0)return INF;
        if(dp[in][k]!=-1)return dp[in][k];
        ll ans=INF;
        for(ll b=in;b<n;b++)
        {   
            ll cst=0;
            for(int i=in;i<=b;i++)cst+=abs(a[i]-a[b]);
            ll res=cst+helper(b+1,k-1,a,dp);
            for(int j=b+1;j<n;j++)
            {
                cst+=a[j]-a[b];
                ll temp=cst+helper(j+1,k-1,a,dp);
                res=min(res,temp);
            }
            ans=min(ans,res);
        }
        return dp[in][k]=ans;
    }

    int minDistance(vector<int>& a, int k) 
    {
        n=a.size();
        sort(a.begin(),a.end());
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        ll ans=helper(0,k,a,dp);
        return ans;
    }
};
