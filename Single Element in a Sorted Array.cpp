class Solution {
public:

    int singleNonDuplicate(vector<int>& nums) 
    {
        int l=0;
        int r=nums.size()-2;

        while(l<=r)
        {
            int mid=(l+r)/2;
            if(mid%2==1)
            {
                if(nums[mid]==nums[mid+1])
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            else
            {
                if(nums[mid]!=nums[mid+1])
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
        }
        return nums[l];
    }
};
