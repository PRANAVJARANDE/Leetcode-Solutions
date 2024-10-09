class Solution {
public:
    int n;
    int helper(int l,int r,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(l>r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int ans=INT_MIN;
        for(int i=l;i<=r;i++)
        {
            int res=nums[i];
            if(l-1>=0)res*=nums[l-1];
            if(r+1<n)res*=nums[r+1];
            int temp=res+helper(l,i-1,nums,dp)+helper(i+1,r,nums,dp);
            ans=max(ans,temp);
        }
        return dp[l][r]=ans;
    }


    int maxCoins(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=helper(0,n-1,nums,dp);
        return ans;
    }
};
