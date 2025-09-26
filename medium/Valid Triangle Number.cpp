class Solution {
public:
    int triangleNumber(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int cs=nums[i]+nums[j];
                int rem=lower_bound(nums.begin(),nums.end(),cs)-nums.begin()-1;
                ans+=max(0,rem-j);
            }
        }
        return ans;
    }
};
