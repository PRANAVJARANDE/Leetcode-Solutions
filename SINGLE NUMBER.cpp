class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int xorsum=0;
        for(int i=0;i<nums.size();i++)
        {
        xorsum=xorsum^nums[i];
        }
        return xorsum;
    }
};
