//MEMOIZATION
class Solution {
public:

    int helper(vector<int>&nums,int in,int pre,vector<vector<int>> &dp)
    {
        if(in==nums.size())
            return 0;

        if(dp[in][pre+1]!= -1)
            return dp[in][pre+1];

        if(pre==-1 || nums[pre]<nums[in])
            return dp[in][pre+1]= max(1+helper(nums,in+1,in,dp),helper(nums,in+1,pre,dp));
        else
            return dp[in][pre+1]=helper(nums,in+1,pre,dp);   
    }


    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return helper(nums,0,-1,dp);
        
    }
};

//TABULATION
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        dp[0]=1;
        int ans=1;
        for(int in=1;in<n;in++)
        {
            for(int pre=0;pre<in;pre++)
            {
                if(nums[pre]<nums[in])
                {
                    dp[in]=max(1+dp[pre],dp[in]);
                }
            }
            ans=max(ans,dp[in]);
        }
        return ans;
    }
};

		
