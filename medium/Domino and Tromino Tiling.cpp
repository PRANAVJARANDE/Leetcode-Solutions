#define ll long long
class Solution {
public:
    
    ll n;
    const int MOD=1e9+7;
    ll helper(ll in,ll t,ll d,vector<vector<vector<ll>>>&dp)
    {
        if(in>=n)return 1;
        if(dp[in][t][d]!=-1)return dp[in][t][d];
        ll op1=0;
        if(t==0 && d==0)
        {
            op1=((op1%MOD)+(helper(in+1,0,0,dp)%MOD))%MOD;
            if(in+1<n)
            {
                op1=((op1%MOD)+(helper(in+1,1,0,dp)%MOD))%MOD;
                op1=((op1%MOD)+(helper(in+1,0,1,dp)%MOD))%MOD;
                op1=((op1%MOD)+(helper(in+1,1,1,dp)%MOD))%MOD;
            }
        }
        else if(t==1 && d==0)
        {
            if(in+1<n)
            {
                op1=((op1%MOD)+(helper(in+1,0,1,dp)%MOD))%MOD;
                op1=((op1%MOD)+(helper(in+1,1,1,dp)%MOD))%MOD;
            }
        }
        else if(t==0 && d==1)
        {
            if(in+1<n)
            {
                op1=((op1%MOD)+(helper(in+1,1,0,dp)%MOD))%MOD;
                op1=((op1%MOD)+(helper(in+1,1,1,dp)%MOD))%MOD;
            }
        }
        else
        {
            op1=((op1%MOD)+(helper(in+1,0,0,dp)%MOD))%MOD;
        }
        return dp[in][t][d]=op1;
    }

    int numTilings(int nn) 
    {
        n=nn;
        vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(2,vector<ll>(2,-1)));
        ll ans=helper(0,0,0,dp);
        return ans;
    }
};
