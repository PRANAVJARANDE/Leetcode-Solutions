class Solution {
public:

    void helper(vector<int>&nums,int in,int &ans)
    {
        if(in==nums.size())
        {
            ans++;
            return;
        }
        for(int i=in;i<nums.size();i++)
        {
            swap(nums[in],nums[i]);
            if((in+1)%nums[in]==0 || nums[in]%(in+1)==0)
            {
                helper(nums,in+1,ans);
            }
            swap(nums[in],nums[i]);
        }
    }


    int countArrangement(int n) {
        vector<int>nums;
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
        int ans=0;
        helper(nums,0,ans);
        return ans;
    }
};
