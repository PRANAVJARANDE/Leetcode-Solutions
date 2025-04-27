class Solution {
public:
    int countSubarrays(vector<int>& nums) 
    {
        int ans=0;
        for(int i=2;i<nums.size();i++)
        {
            int i1=nums[i-2];
            int i2=nums[i-1];
            int i3=nums[i];
            if(2*(i1+i3)==i2)ans++;
        }
        return ans;
    }
};
