//Tabulation
class Solution {
public:

    bool canJump(vector<int>& nums) 
    {
        int n=nums.size();
        vector<bool>dp(n,0);
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j] && j+nums[j]>=i)
                {
                    dp[i]=1;
                    break;
                }
                
            }
        }
        return dp[n-1];
    }
};

//Memoization
class Solution {
public:

    bool helper(vector<int>& nums,int in,int des,vector<int>&dp)
    {
        if(in==des)
        return 1;

        if(dp[in]!=-1)
        return dp[in];

        for(int i=1;i<=nums[in];i++)
        {
            if(helper(nums,in+i,des,dp))
            return dp[in]=1;
        }
        return dp[in]=0;
    }


    bool canJump(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(n,-1);
        return helper(nums,0,n-1,dp);
    }
};
