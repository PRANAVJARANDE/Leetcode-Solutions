class Solution {
public:

    void helper(vector<vector<int>> &ans,vector<int> nums,int in)
    {
        int n=nums.size();
        if(in==n-1)
        {
            ans.push_back(nums);
            return;
        }
        for(int i=in;i<n;i++)
        {
            swap(nums[i],nums[in]);
            helper(ans,nums,in+1);
            swap(nums[i],nums[in]);
        }
    }


    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        helper(ans,nums,0);
        return ans;
    }
};
