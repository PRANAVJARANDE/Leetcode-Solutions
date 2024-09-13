class Solution {
public:

    void helper(set<vector<int>> &ans,vector<int> nums,int in)
    {
        int n=nums.size();
        if(in==n-1)
        {
            ans.insert(nums);
            return;
        }
        for(int i=in;i<n;i++)
        {
            if(nums[i]==nums[in] && in!=i)
            {
                continue;
            }
            swap(nums[i],nums[in]);
            helper(ans,nums,in+1);
            swap(nums[i],nums[in]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s1;
        helper(s1,nums,0);
        for(auto x: s1)
        ans.push_back(x);
        return ans;
    }
};
