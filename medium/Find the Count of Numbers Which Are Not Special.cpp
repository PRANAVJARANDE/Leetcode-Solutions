typedef long long ll;
class Solution {
public:
    
    ll n=1e5;
    vector<bool>prime;
    vector<ll>pri;
    void sieve()
    {
        prime.resize(n+2,1);
        for (int p = 2; p * p <= n; p++) {
            if (prime[p]) 
            {
                for (int i = p * p; i <= n+1; i += p) {
                    prime[i] = false;
                }
            }
        }
        for(ll i=2;i<=n;i++)
        {
            if(prime[i]==1)
                pri.push_back(i);
        }
    }

    int nonSpecialCount(int l, int r) 
    {
        ll ans=r-l+1;
        sieve();
        for(ll x:pri)
        {
            x=x*x;
            if(l<=x && x<=r)
            {
                ans--;
            }
        }
        return ans;
        
    }
};
