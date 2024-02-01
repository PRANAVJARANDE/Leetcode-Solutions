class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=2;i<n;i++)
        {
            if(nums[i]-nums[i-2]<=k)
            {
                ans.push_back({nums[i-2],nums[i-1],nums[i]});
                i+=2;
            }
        }
        if(ans.size()!=n/3)
        {
            return vector<vector<int>>();
        }
        return ans;
        
    }
};
