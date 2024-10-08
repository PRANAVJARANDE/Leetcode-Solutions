class Solution {
public:
    int maximumJumps(vector<int>& nums, int t) 
    {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(abs(nums[i]-nums[j])<=t && dp[j]!=-1)
                {
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        return dp[n-1];
    }
};
