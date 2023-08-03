class Solution {
public:

    int helper(vector<int>&nums,int in,int b,int n,int m,vector<vector<vector<int>>> &dp)
    {
        if(in>=n)
            return 0;

        if(dp[in][m][b]!=-1)
            return dp[in][m][b];

        int s=0;
        int ans;
        if(b==0)
        {
            ans=0;
        }
        else
        {
            ans=INT_MAX;
        }
        for(int i=1;i<=2*m;i++)
        {
            int pi=in+i-1;
            if(pi>=n)
                break;
            s+=nums[pi];

            if(b==0)
            {
                ans=max(ans,s+helper(nums,pi+1,1,n,max(m,i),dp));
            }
            else
            {
                ans=min(ans,helper(nums,pi+1,0,n,max(m,i),dp));
            }
        }
        return dp[in][m][b]=ans;
    }


    int stoneGameII(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2*n,vector<int>(2,-1)));
        return helper(nums,0,0,n,1,dp);
    }
};
