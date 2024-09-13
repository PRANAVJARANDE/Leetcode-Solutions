class Solution {
public:
    int n;
    int helper(vector<int>&nums,int k,int in,int t,bool b,vector<vector<vector<int>>>&dp)
    {
        if(in>=n)
        {
            return 0;
        }
        if(t>k)
        {
            return 0;
        }

        if(dp[in][t][b]!=-1)
        {
            return dp[in][t][b];
        }

        if(b==0)
        {
            int buy=-nums[in]+helper(nums,k,in+1,t+1,1,dp);
            int nbuy=helper(nums,k,in+1,t,0,dp);
            return  dp[in][t][b]=max(buy,nbuy);
        }
        else
        {
            int sell=nums[in]+helper(nums,k,in+1,t,0,dp);
            int nsell=helper(nums,k,in+1,t,1,dp);
            return  dp[in][t][b]=max(sell,nsell);
        }
    }

    int maxProfit(int k, vector<int>& nums) {
        n=nums.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return helper(nums,k,0,0,0,dp);
    }
};
