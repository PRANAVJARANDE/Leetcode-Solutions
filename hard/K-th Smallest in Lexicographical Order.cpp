#define ll long long
class Solution {
public:

    ll helper(ll a,ll b,ll n)
    {
        ll ans=0;
        while(a<=n)
        {
            ans+=min(n+1,b)-a;
            a*=10;
            b*=10;
        }
        return ans;
    }

    int findKthNumber(int n, int k) 
    {
        ll ans=1;
        k--;
        while(k)
        {
            ll sp=helper(ans,ans+1,n);
            if(sp<=k)
            {
                ans++;
                k-=sp;
            }
            else
            {
                k--;
                ans=ans*10;
            }
        }
        return ans;
    }
};
