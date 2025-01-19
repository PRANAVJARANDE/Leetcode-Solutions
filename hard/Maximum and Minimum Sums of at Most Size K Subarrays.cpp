#define ll long long
class Solution {
public:

    ll helper(ll a,ll b,ll k)
    {
        if(a>b)swap(a,b);

        ll ans=0;
        ll tr=min(a+1,k);
        ans+=((tr)*(tr+1))/2;
        if(k==tr)return ans;
        ll z=tr;

        ll nx=min(k,b+1)-z;
        z+=nx;
        ans+=(a+1)*nx;
        if(z==k)return ans;

        ll ls=min(k-z,a);
        ans+=ls*(a+1);
        ans-=(ls*(ls+1))/2;
        return ans;
    }

    long long minMaxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>nmin(n,n);
        vector<int>nmax(n,n);
        vector<int>pmin(n,-1);
        vector<int>pmax(n,-1);
        
        stack<int> smin, smax;

        for (int i = 0; i < n; i++) {
            while (!smin.empty() && nums[smin.top()] > nums[i]) {
                nmin[smin.top()] = i;
                smin.pop();
            }
            if (!smin.empty()) {
                pmin[i] = smin.top();
            }
            smin.push(i);
        }

        for (int i = 0; i < n; i++) {
            while (!smax.empty() && nums[smax.top()] < nums[i]) {
                nmax[smax.top()] = i;
                smax.pop();
            }
            if (!smax.empty()) {
                pmax[i] = smax.top();
            }
            smax.push(i);
        }
        
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            int lb1=max(max(0,pmin[i]+1),i-k+1);
            int rb1=min(min(n-1,nmin[i]-1),i+k-1);
            int lb2=max(max(0,pmax[i]+1),i-k+1);
            int rb2=min(min(n-1,nmax[i]-1),i+k-1);
            
            ll r1=helper(i-lb1,rb1-i,k);
            ll r2=helper(i-lb2,rb2-i,k);
            //cout<<r1<<" "<<r2<<endl;
            ans+=(r1+r2)*nums[i];
        }
        return ans;
    }
};
