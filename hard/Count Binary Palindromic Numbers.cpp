#define ll long long

class Solution {
public:

    ll makeP(ll h, int len) 
    {
        ll res=h;
        ll temp=h;
        
        if(len%2) 
        {
            temp>>= 1;
        }
        for (int i=0;i<len/2;i++) 
        {
            res <<= 1;
            res |= (temp & 1);
            temp >>= 1;
        }
        return res;
    }

    long long countBinaryPalindromes(long long n) 
    {
        if(n==0)return 1;
        if(n==1)return 2;

        ll ans=1;
        ll l=0;
        ll temp=n;
        while(temp) 
        {
            temp/=2;
            l++;
        }

        for(int i=1;i<l;i++) 
        {
            int hf=(i-1)/2;
            ans+=(1LL<<hf);
        }

        int hf=(l+1)/2;
        ll h_n=n>>(l/2);
        ll min_h=(1LL << (hf - 1));
        ans+=(h_n-min_h);
        ll p=makeP(h_n,l);
        if(p<=n)ans++;
        return ans;
    }
};
