class Solution {
public:
    void helper(vector<int>&nums,vector<int>&v1,vector<vector<int>>&ans,int in,int t)
    {
        if(in>=nums.size())
        {
            return ;
        }
        if(t==0)
        {
            ans.push_back(v1);
            return;
        }
        if(t<0)
        {
            return;
        }
        //take
        v1.push_back(nums[in]);
        helper(nums,v1,ans,in,t-nums[in]);
        v1.pop_back();
        helper(nums,v1,ans,in+1,t);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int t) 
    {
        vector<vector<int>> ans;
        vector<int> v1;
        helper(arr,v1,ans,0,t);
        return ans;
    }
};
