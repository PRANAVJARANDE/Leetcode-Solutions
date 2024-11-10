class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>cnt(32,0);
        int d=0;
        int l=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            d|=nums[i];
            for(int j=0;j<32;j++)
            {
                if(nums[i] & (1<<j))
                {
                    cnt[j]++;
                }
            }
            while(l<=i && d>=k)
            {
                ans=min(ans,i-l+1);
                d=0;
                for(int j=0;j<32;j++)
                {
                    if(nums[l] & (1<<j))
                    {
                        cnt[j]--;
                    }
                }
                d=0;
                for(int j=0;j<32;j++)
                {
                    if(cnt[j]>0)
                    {
                        d= d | (1<<j);
                    }
                }
                l++;
            }
        }
        if(ans==INT_MAX)ans=-1;
        return ans;
    }
};
