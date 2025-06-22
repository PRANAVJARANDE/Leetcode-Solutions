class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int h=nums[nums[0]];
        int t=nums[0];
        while(h!=t)
        {
            t=nums[t];
            h=nums[nums[h]];
        }
        //find tuch point
        int t2=0;
        while(t2!=t)
        {
            t2=nums[t2];
            t=nums[t];
        }
        return t;
    }
};
