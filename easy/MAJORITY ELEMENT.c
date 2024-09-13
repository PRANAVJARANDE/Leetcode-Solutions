class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int n=nums.size();
        int h=n/2;

        sort(nums.begin(),nums.end());

        int k=1;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                k++;
            }
            else
            {
                k=1;
            }
            if(k>h)
            {
                return nums[i];
            }
        }

    return nums[0];

    }
};
