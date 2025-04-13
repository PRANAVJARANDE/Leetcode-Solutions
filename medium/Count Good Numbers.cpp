#define ll long long
class Solution {
public:

    int MOD=1E9 + 7;
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


    int countGoodNumbers(long long n) 
    {
        ll od=n/2;
        ll ev=n-od;
        ll ans=((mod_pow(5,ev,MOD)%MOD)*(mod_pow(4,od,MOD)%MOD))%MOD;
        int res=ans;
        return res;
    }
};
