
//TABULATION
class Solution {
public:

    int jump(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> dp(n,0);
        for(int i=n-2;i>=0;i--)
        {
            int sa=INT_MAX-1;
            for(int j=1;j<=min(nums[i],n-1-i);j++)
            {
                sa=min(sa,1+dp[i+j]);
            }
            dp[i]=sa;
        }
        return dp[0];
    }
};

//MEMOIZATION
class Solution {
public:

    long long helper(vector<int>&nums,int in,int dest,vector<long long> &dp)
    {
        if(in>=dest)
            return 0;

        if(dp[in]!=-1)
            return dp[in];

        dp[in]=INT_MAX;
        for(int i=1;i<=nums[in];i++)
        {
            dp[in]=min(dp[in],1+helper(nums,in+i,dest,dp));
        }
        return dp[in];
    }


    int jump(vector<int>& nums) 
    {
        vector<long long> dp(nums.size(),-1);
        return helper(nums,0,nums.size()-1,dp);
    }
};
