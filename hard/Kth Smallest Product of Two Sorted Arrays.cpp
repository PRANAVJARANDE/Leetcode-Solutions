#define ll long long
class Solution {
public:

    ll helper(ll mid,vector<int>&a1,vector<int>&a2)
    {
        ll n=a1.size(),m=a2.size();
        ll ans=0;
        for(auto x:a1)
        {
            if(x==0)
            {
                if(0<=mid)ans+=m;
                continue;
            }
            if(x<0)
            {   
                ll v=ceil((double)mid/(double)x);
                ll cnt=m-(lower_bound(a2.begin(),a2.end(),v)-a2.begin());
                ans+=cnt;
            }
            else
            {
                ll v=floor((double)mid/x);
                ll cnt=(upper_bound(a2.begin(),a2.end(),v)-a2.begin());
                ans+=cnt;
            }
        }
        return ans;
    }

    long long kthSmallestProduct(vector<int>& a1, vector<int>& a2, long long k) 
    {
        int n=a1.size(),m=a2.size();
        ll op1=(ll)a1[0]*a2[0];
        ll op2=(ll)a1[n-1]*a2[m-1];
        ll op3=(ll)a1[0]*a2[m-1];
        ll op4=(ll)a1[n-1]*a2[0];

        ll l=min(min(op1,op2),min(op3,op4));
        ll r=max(max(op1,op2),max(op3,op4));

        ll ans=-1;
        while(l<=r)
        {
            ll mid=l+(r-l)/2;
            ll cnt=helper(mid,a1,a2);
            if(k<=cnt)
            {
                ans=mid;
                r=mid-1;
            }
            else 
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
