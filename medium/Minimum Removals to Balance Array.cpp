#define ll long long
class Solution {
public:

    ll n;
    bool check(ll mid,vector<int>&nums,ll k)
    {
        mid--;
        for(int i=mid;i<n;i++)
        {
            if(nums[i]<=(ll)k*nums[i-mid])return 1;
        }
        return 0;
    }

    int minRemoval(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        n=nums.size();
        ll l=2,r=n;
        ll ans=1;
        while(l<=r)
        {
            ll mid=l+(r-l)/2;
            if(check(mid,nums,k))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return n-ans;
    }
};
