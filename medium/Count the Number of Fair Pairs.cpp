class Solution {
public:

    int n;
    int lowhel(vector<int>& nums,int l,int r,int k)
    {
        int ans=n;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]>=k)
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

    int uphel(vector<int>& nums,int l,int r,int k)
    {
        int ans=n;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]>k)
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


    long long countFairPairs(vector<int>& nums, int l, int u) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        n=nums.size();
        for(int x:nums)
        {
            int mini=l-x,maxi=u-x;
            if(l<=2*x && 2*x<=u)ans--;
            int j1=lowhel(nums,0,n-1,mini);
            int j2=uphel(nums,0,n-1,maxi);
            ans+=j2-j1;
        }
        return ans/2;
    }
};
