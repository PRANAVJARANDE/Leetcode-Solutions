#define ll long long 
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) 
    {
        ll ans=0;
        ll l=0;
        ll n=nums.size();
        ll s=0;
        for(int i=0;i<n;i++)
        {
            s+=nums[i];
            while((i-l+1)*s>=k)
            {
                s-=nums[l];
                l++;
            }
            ans+=max(0ll,i-l+1);
        }
        return ans;
    }
};
