class Solution {
public:
    long long minimumReplacement(vector<int>& nums) 
    {
        long long ans=0;
        int n=nums.size();
        int i=n-2,pre=nums[n-1];
        while(i>=0)
        {
            if(nums[i]<=pre)
            {
                pre=nums[i];
                i--;
            }
            else
            {
                int g=ceil((double)nums[i]/(double)pre);
                ans+=(g-1);
                pre=nums[i]/g;
                i--;
            }
        }
        return ans;
    }
};
