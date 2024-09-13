class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        vector<int> ans;
        int n=nums.size();
        if(n<3)
        {
            for(int i=0;i<n;i++)
            {
                if(ans.size()!=0 && ans.back()!=nums[i])
                {
                    ans.push_back(nums[i]);
                }
                if(ans.size()==0)
                {
                    ans.push_back(nums[i]);
                }
            }
            return ans;
        }
        sort(nums.begin(),nums.end());
        
        int c=n/3;
        for(int i=0;i<n-c;i++)
        {
            if(nums[i]==nums[i+c])
            {
                if(ans.size()!=0 && ans.back()!=nums[i])
                {
                    ans.push_back(nums[i]);
                }
                if(ans.size()==0)
                {
                    ans.push_back(nums[i]);
                }
                i=i+c;
            }
        }
        return ans;
    }
};
