class Solution {
public:
    vector<int> transformArray(vector<int>& nums) 
    {
        int n=nums.size();
        int in=0;
        vector<int>ans(n,1);
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                ans[in++]=0;
            }
        }
        return ans;
    }
};
