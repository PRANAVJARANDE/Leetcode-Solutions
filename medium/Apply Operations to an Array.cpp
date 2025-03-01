class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>ans(n,0);
        int in=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]!=0)
            {
                if(nums[i]==nums[i+1])
                {
                    ans[in++]=2*nums[i];
                    nums[i+1]=0;
                }
                else
                {
                    ans[in++]=nums[i];
                }
            }
        }
        if(nums[n-1]!=0)ans[in]=nums[n-1];
        return ans;
    }
};
