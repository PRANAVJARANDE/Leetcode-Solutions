class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int currsum=0,msum=INT_MIN;



        int k=0,ma=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                k++;
            }
            ma=max(ma,nums[i]);
        }
        if(k==nums.size())
        {
            return ma;
        }










        for(int i=0;i<nums.size();i++)
        {
            currsum=currsum+nums[i];
            if(currsum<0)
            {
                currsum=0;
            }
            msum=max(msum,currsum);
        }

        return msum;
    }
};
