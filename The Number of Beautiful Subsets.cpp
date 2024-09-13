class Solution {
public:

    int n;
    unordered_map<int,int> s1;
    int ans;
    void helper(int in,vector<int>&nums,int k)
    {
        if(in>=n)
        {
            ans++;
            return;
        } 
        //take
        if(s1.find(nums[in]-k)==s1.end() && s1.find(nums[in]+k)==s1.end())
        {
            s1[nums[in]]++;
            helper(in+1,nums,k);
            s1[nums[in]]--;
            if(s1[nums[in]]==0)s1.erase(nums[in]);
        }
        //not take
        helper(in+1,nums,k);
    }

    int beautifulSubsets(vector<int>& nums, int k) 
    {
        ans=0;
        n=nums.size();
        helper(0,nums,k);
        return ans-1;
    }
};
