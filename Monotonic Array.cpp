class Solution {
public:
    bool isMonotonic(vector<int>& nums) 
    {
        int n=nums.size();
        bool b=0;
        if(nums[0]>nums[n-1])
        {
            b=1;
        }
        for(int i=1;i<n-1;i++)
        {
            if(nums[i-1]==nums[i] && nums[i]==nums[i+1])
            {
                continue;
            }
            if(nums[i-1]<=nums[i] && nums[i]<=nums[i+1])
            {
                if(b==1)
                {
                    return 0;
                }
            }
            else if(nums[i-1]>=nums[i] && nums[i]>=nums[i+1])
            {
                if(b==0)
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }    
        return 1;
    }
};
