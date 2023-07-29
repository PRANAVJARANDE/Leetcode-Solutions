class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0;
        int ans=0;
        int n=nums.size();
        int p=1;
        if(k==0 || k==1)
            return 0;
        for(int i=0;i<n;i++)
        {
            p=p*nums[i];
            while(p>=k && l<n)
            {
                ans=ans+i-l;
                p=p/nums[l];
                l++;
            }
        }
        while(l<n)
        {
            ans+=n-l;
            l++;
        }
        return ans;
    }
};
