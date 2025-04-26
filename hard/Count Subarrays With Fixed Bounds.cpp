#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mini, int maxi) 
    {
        ll n=nums.size();
        vector<ll>pv(n,-1);
        ll nxtemp=-1;
        for(int i=0;i<n;i++)
        {
            if(!(mini<=nums[i] && nums[i]<=maxi))nxtemp=i;
            pv[i]=nxtemp;
        }

        ll i1=-1,i2=-1;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            if(!(mini<=nums[i] && nums[i]<=maxi))
            {
                i1=-1;
                i2=-1;
            }
            else
            {
                if(nums[i]==maxi)i2=i;
                if(nums[i]==mini)i1=i;
                if(i1!=-1 && i2!=-1)
                {
                    ll p1=min(i1,i2)-pv[i];
                    ans+=p1;
                }
            }
        }
        return ans;
    }
};
