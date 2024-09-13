class Solution {
public:

    int maxResult(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int>dp(n,INT_MIN);
        dp[n-1]=nums[n-1];
        priority_queue<pair<int,int>> q1;
        q1.push({dp[n-1],n-1});
        
        for(int in=n-2;in>=0;in--)
        {
            while(!q1.empty() && q1.top().second>in+k)
            {
                q1.pop();
            }
            dp[in]=nums[in]+q1.top().first;
            q1.push({dp[in],in});
        }
        return dp[0];
    }
};
