class Solution {
public:
        int n;
        int helper(vector<int>&nums,int in,int maxi,vector<vector<int>>&dp)
        {
                if(in>=n)
                {
                        return 0;
                }
                
                if(dp[in][maxi]!=-1)
                        return dp[in][maxi];
                
                if(nums[in]==maxi)
                {
                        return dp[in][maxi]=helper(nums,in+1,maxi,dp);
                }
                if(nums[in]<maxi)
                {
                        return dp[in][maxi]=1+helper(nums,in+1,maxi,dp);
                }
                int op1=1+helper(nums,in+1,maxi,dp);
                int op2=helper(nums,in+1,nums[in],dp);
                return dp[in][maxi]=min(op1,op2);
        }
        
    int minimumOperations(vector<int>& nums) 
    {
         n=nums.size();
         vector<vector<int>>dp(n,vector<int>(4,-1));
         return helper(nums,0,1,dp);
    }
};
