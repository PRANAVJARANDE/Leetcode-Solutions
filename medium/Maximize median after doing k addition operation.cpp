#define ll long long
class Solution {
  public:
  
    bool check(ll mid,vector<int>&a,int k)
    {
        ll n=a.size();
        if(n%2)
        {
            ll cnt=0;
            for(int i=n/2;i<n;i++)
            {
                cnt+=max(0ll,mid-a[i]);
            }
            return cnt<=k;
        }
        else
        {
            ll cs=a[n/2]+a[(n/2)-1];
            ll rs=2*mid;
            
            ll cnt=max(0ll,rs-cs);
            for(int i=n/2 +1;i<n;i++)
            {
                cnt+=max(0ll,mid-a[i]);
            }
            return cnt<=k;
        }
               
    }
 
    int maximizeMedian(vector<int>& a, int k) 
    {
        sort(a.begin(),a.end());
        ll n=a.size();
        ll l=0,r=1e9;
        if(n%2)l=a[n/2];
        else l=(a[n/2]+a[(n/2)-1])/2;
        ll ans=l;
        while(l<=r)
        {
            ll mid=l+(r-l)/2;
            if(check(mid,a,k))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};
