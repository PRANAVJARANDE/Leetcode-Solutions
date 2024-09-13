class Solution {
public:
    int countPairs(vector<int>& nums, int t) 
    {
        int ans=0,n=nums.size();
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                        if(nums[j]+nums[i]<t)
                        {
                                ans++;
                        }
                }
            }
            return ans;
        
    }
};
