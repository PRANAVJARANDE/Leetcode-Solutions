class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int k=1,ans=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                continue;
            }
            if(nums[i]+1==nums[i+1])
            {
                k++;
            }
            else
            {
                ans=max(ans,k);
                k=1;
            }
        }
        ans=max(ans,k);
        return ans;
        
    }
};
