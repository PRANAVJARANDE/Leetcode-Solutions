class Solution {
public:

    int helper(vector<int>&nums,vector<int> &cost,int in,int dest,vector<int>&dp)
    {
        if(in>=dest)
            return 0;

        if(dp[in]!=-1)
        {
            return dp[in];
        }

        int op1=cost[0]+helper(nums,cost,in+1,dest,dp);
        int op2=cost[1]+helper(nums,cost,lower_bound(nums.begin(),nums.end(),nums[in]+7)-nums.begin(),dest,dp);
        int op3=cost[2]+helper(nums,cost,lower_bound(nums.begin(),nums.end(),nums[in]+30)-nums.begin(),dest,dp);
        return dp[in]=min(op3,min(op1,op2));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n,-1);
        return helper(days,costs,0,n,dp);
    }
};
