#define ll long long
class Solution {
public:
    const ll MOD=1E9+7;
    ll mod_pow(ll a,ll b)
    {
        if(b==0)return 1;
        if(b%2)
        {
            return ((a%MOD)*(mod_pow(a,b-1)%MOD))%MOD;
        }
        else
        {
            ll temp=mod_pow(a,b/2)%MOD;
            return ((temp%MOD)*(temp%MOD))%MOD;
        }
    }

    vector<int> productQueries(int n, vector<vector<int>>& q) 
    {
        vector<ll>v1;
        for(int i=0;i<32;i++)
        {
            if(n & (1<<i))v1.push_back(i);
        }
        for(int i=1;i<v1.size();i++)v1[i]+=v1[i-1];
        vector<int>ans;
        for(auto x:q)
        {
            ll l=x[0];
            ll r=x[1];
            ll sm=v1[r];
            if(l-1>=0)sm-=v1[l-1];
            int res=mod_pow(2,sm)%MOD;
            ans.push_back(res);
        }
        return ans;
    }
};
