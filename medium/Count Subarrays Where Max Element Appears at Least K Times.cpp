#define ll long long 
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=0;
        for(auto x:nums)maxi=max(maxi,x);
        int n=nums.size();
        ll ans=0;
        int cnt=0,l=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==maxi)cnt++;
            while(cnt==k)
            {
                ans+=n-i;
                if(nums[l]==maxi)cnt--;
                l++;
            }
        }
        return ans;
    }
};
