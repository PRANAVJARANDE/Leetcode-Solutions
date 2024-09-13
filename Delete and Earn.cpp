class Solution {
public:

    int helper(vector<int> & nums,int in,int dest,unordered_map<int,int>&m,vector<int>&dp)
    {
        if(in>=dest)
            return 0;

        if(dp[in]!=-1)
            return dp[in];

        int ntake=helper(nums,in+m[nums[in]],dest,m,dp);
        int i=m[nums[in]]+m[nums[in]+1];
        int take=m[nums[in]]*nums[in]+ helper(nums,in+i,dest,m,dp);
        return dp[in]=max(take,ntake);
    }

    int deleteAndEarn(vector<int>& nums) 
    {
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        vector<int> dp(n+1,-1);
        sort(nums.begin(),nums.end());
        return helper(nums,0,n,m,dp);
    }
};
