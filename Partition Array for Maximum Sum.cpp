class Solution {
public:
    int n;
    int helper(int in,vector<int>&arr,int k,vector<int>&dp)
    {
        if(in>=n)return 0;

        if(dp[in]!=-1)return dp[in];
        int sz=0,ans=INT_MIN,maxi=INT_MIN;
        for(int i=in;i<min(n,in+k);i++)
        {
            sz++;
            maxi=max(maxi,arr[i]);
            int sum=sz*maxi+helper(i+1,arr,k,dp);
            ans=max(ans,sum);
        }
        return dp[in]=ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        n=arr.size();
        vector<int>dp(n,-1);
        return helper(0,arr,k,dp);
    }
};
