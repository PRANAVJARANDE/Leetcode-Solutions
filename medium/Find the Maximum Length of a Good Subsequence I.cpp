class Solution {
public:
    int n;
    int helper(int in, int prev, int cnt, vector<int>& nums, int k, vector<vector<vector<int>>>& dp) {
        if(cnt>k) return INT_MIN;
        if(in>=n)return 0;
        if(dp[in][prev][cnt]!=-1) return dp[in][prev][cnt];
        int mx=1;
        for(int p=0;p<in;p++)
        {
            if(nums[p]==nums[in])
            {
                mx=max(mx,1+helper(p,prev,cnt,nums,k,dp));
            }
            else if(cnt>0)
            {
                mx=max(mx,1+helper(p,prev,cnt-1,nums,k,dp));
            }
        }
        return dp[in][prev][cnt]=mx;
    }
    
    int maximumLength(vector<int>& nums, int k) {
        n = nums.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        int ans=1;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,helper(i,0,k,nums,k,dp));
        }
        return ans;
    }
};
