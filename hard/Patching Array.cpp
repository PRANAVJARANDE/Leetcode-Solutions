class Solution {
public:
    int minPatches(vector<int>& nums, int n) 
    {
        long long ans=0;
        long long in=1;
        long long i=0;
        while(in<=n)
        {
            if(i<nums.size() && nums[i]<=in)
            {
                in+=nums[i];
                i++;
            }
            else
            {
                ans++;
                in+=in;
            }
        }
        return ans;
    }
};
