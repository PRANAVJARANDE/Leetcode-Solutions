class Solution {
public:

    void helper(vector<int>&nums,vector<int>&v1,vector<vector<int>>&ans,int in,int t)
    {
        if(t==0)
        {
            ans.push_back(v1);
            return;
        }
        if(t<0)
        {
            return;
        }
        
        for(int i=in;i<nums.size();i++)
        {
            if(nums[i] > t) 
            {
                break;
            }
            if(i>in && nums[i]==nums[i-1])
            {
                continue;
            }
            v1.push_back(nums[i]);
            helper(nums,v1,ans,i+1,t-nums[i]);
            v1.pop_back();
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& nums, int t) 
    {
        sort(nums.begin(),nums.end());
        vector<int> v1;
        vector<vector<int>> ts;
        helper(nums,v1,ts,0,t);
        return ts;
    }
};
