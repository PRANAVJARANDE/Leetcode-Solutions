class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) 
    {
            int n=nums.size();
            vector<long long>dp(n+1,1e18);
            dp[0]=0;
            
            for(int i=1;i<=n;i++)
            {
                long long req=max(0,k-nums[i-1]);
                for(int j=i-1;j>=max(0,i-3);j--)
                {
                        dp[i]=min(dp[i],dp[j]);
                }
                dp[i]+=req;
            }
            
            return min(dp[n],min(dp[n-1],dp[n-2]));  
    }
};
