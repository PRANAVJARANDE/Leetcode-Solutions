class Solution {
public:
    int n;

    bool getbit(int n,int i)
    {
        return n & (1<<i);
    }

    int helper(vector<int>&nums1,vector<int>&nums2,int in,int tracer,vector<vector<int>>&dp)
    {
        if(in>=nums1.size())
        {
            return 0;
        }
        if(dp[in][tracer]!=-1)
        {
            return dp[in][tracer];
        }
        int ans=INT_MAX;
        for(int i=0;i<nums2.size();i++)
        {
            if(getbit(tracer,i)==0)
            {
                ans=min(ans,(nums1[in]^nums2[i]) +helper(nums1,nums2,in+1,tracer|(1<<i),dp));
            }
        }
        return dp[in][tracer]=ans;
    }

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        vector<vector<int>>dp(n,vector<int>(1<<n,-1));
        return helper(nums1,nums2,0,0,dp);
    }
};
