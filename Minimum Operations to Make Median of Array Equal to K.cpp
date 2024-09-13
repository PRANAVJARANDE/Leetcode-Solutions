class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mid=n/2;
        
        if(nums[mid]==k)
        {
            return 0;
        }
        else if(nums[mid]>k)
        {
            long long ans=0;
            for(int i=0;i<=mid;i++)
            {
                if(k<nums[i])
                {
                    ans+=nums[i]-k;
                }
            }
            return ans;
        }
        else
        {
            long long ans=0;
            for(int i=mid;i<n;i++)
            {
                if(k>nums[i])
                {
                    ans+=k-nums[i];
                }
            }
            return ans;
        }
        
        
    }
};
