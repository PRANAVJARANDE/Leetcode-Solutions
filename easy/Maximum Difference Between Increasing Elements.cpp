class Solution {
public:
    int maximumDifference(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=-1;
        int maxi=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<maxi)
            {
                ans=max(ans,maxi-nums[i]);
            }
            maxi=max(maxi,nums[i]);
        }
        return ans;
    }
};
