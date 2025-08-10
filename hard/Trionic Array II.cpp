#define ll long long 
class Solution {
public:
    long long maxSumTrionic(vector<int>& a) 
    {
        ll n=a.size();

        vector<ll>pcheck(n,0),qcheck(n,0);
        for(int i=1;i<n-1;i++)if(a[i-1]>a[i] && a[i]<a[i+1])qcheck[i]=1;
        for(int i=1;i<n-1;i++)if(a[i-1]<a[i] && a[i]>a[i+1])pcheck[i]=1;


        vector<ll>v1(n,0);
        vector<ll>v2(n,0);

        for(int i=n-2;i>=1;i--)
        {
            if(pcheck[i]==1)
            {
                ll in=i-1;
                ll cs=0;
                ll maxi=LLONG_MIN;
                while(in>=0 && a[in]<a[in+1])
                {
                    cs+=a[in];
                    maxi=max(maxi,cs);
                    in--;
                }
                v1[i]=maxi;
            }
        }

        for(int i=1;i<n-1;i++)
        {
            if(qcheck[i]==1)
            {
                ll in=i+1;
                ll cs=0;
                ll maxi=LLONG_MIN;
                while(in<n && a[in-1]<a[in])
                {
                    cs+=a[in];
                    maxi=max(maxi,cs);
                    in++;
                }
                v2[i]=maxi;
            }
        }

        ll ans=LLONG_MIN;
        for(int i=1;i<n-1;i++)
        {
            if(pcheck[i]==1)
            {
                ll sum=v1[i];
                while(i+1<n && a[i]>a[i+1])
                {
                    sum+=a[i];
                    i++;
                }
                sum+=a[i];
                if(qcheck[i])
                {
                    sum+=v2[i];
                    ans=max(ans,sum);
                }
            }
        }
        return ans;
    }
};


