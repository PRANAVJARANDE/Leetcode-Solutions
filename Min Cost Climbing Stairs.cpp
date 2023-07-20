class Solution {
public:

    int helper(int s,vector<int> &nums,int dest,vector<int> &dp)
    {
        if(s>=dest)
            return 0;

        if(dp[s]!=-1)
            return dp[s];

        return dp[s]=nums[s]+min(helper(s+1,nums,dest,dp),helper(s+2,nums,dest,dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+2,-1);
        return min(helper(0,cost,n,dp),helper(1,cost,n,dp));
    }
};

class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,0);
        dp[n-1]=cost[n-1];
        dp[n-2]=cost[n-2];
        
        for(int s=n-3;s>=0;s--)
        {
            dp[s]=cost[s]+min(dp[s+1],dp[s+2]);
        }
        return min(dp[0],dp[1]);
    }
};
