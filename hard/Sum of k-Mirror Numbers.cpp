#define ll long long
class Solution {
public:

    bool check(ll num,int k)
    {
        vector<int> v1;
        while(num)
        {
            v1.push_back(num%k);
            num/=k;
        }
        int n=v1.size();
        for(int i=0;i<n/2;i++)
        {
            if(v1[i]!=v1[n-i-1])return 0;
        }
        return 1;
    }

    ll help(ll num,bool od)
    {
        ll ans=num;
        if(od)num/=10;
        while(num)
        {
            ans=ans*10 + num%10;
            num/=10;
        }
        return ans;
    }

    long long kMirror(int k, int n) 
    {
        ll ans=0;
        ll dig=1;
        while(1)
        {
            ll hf=(dig+1)/2;
            ll l=powl(10,hf-1);
            ll r=powl(10,hf)-1;
            for(int i=l;i<=r;i++)
            {
                ll v=i;
                ll num=help(i,dig%2);
                if(check(num,k))
                {
                    ans+=num;
                    n--;
                    if(n==0)return ans;
                }
            }
            dig++;
        }   
        return 0;
        
    }
};
