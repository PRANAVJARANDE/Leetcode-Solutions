class Solution {
public:

    bool check(int m,vector<int>&nums,int k)
    {
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=m)
            {
                c++;
                i++;
            }
        }
        if(c>=k)return 1;
        return 0;
    }

    int minCapability(vector<int>& nums, int k)
    {
        int l=1,r=1;
        for(auto x:nums)r=max(r,x);
        int ans=r;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(check(m,nums,k))
            {
                ans=m;
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return ans;
    }
    
};
