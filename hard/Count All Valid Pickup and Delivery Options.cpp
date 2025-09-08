#define ll long long 
class Solution {
public:

    ll n;
    const ll MOD=1e9 + 7;
    ll helper(int in,int open,vector<vector<ll>>&dp)
    {
        if(open<0)return 0;
        if(in==(2*n)-1)
        {
            if(open==1)return 1;
            return 0;
        }
        if(dp[in][open]!=-1)return dp[in][open];
        ll op1=helper(in+1,open+1,dp)%MOD;
        ll op2=0;
        if(open-1>=0)op2=((open%MOD)*(helper(in+1,open-1,dp)%MOD))%MOD;
        return dp[in][open]=(op1%MOD+op2%MOD)%MOD;
    }

    int countOrders(int nn) 
    {
        n=nn;
        vector<vector<ll>>dp(2*n+2,vector<ll>(2*n+2,-1));
        ll res=helper(0,0,dp)%MOD;
        for(int i=1;i<=n;i++)res=(((res%MOD)*(i%MOD))%MOD);
        return res;
    }
};
