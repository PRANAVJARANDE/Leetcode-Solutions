class Solution {
public:

    int n;
    int helper(vector<vector<int>>& arr,int in,vector<int>&dp)
    {
        if(in>=n)
            return 0;

        if(dp[in]!=-1)
            return dp[in];

        int op1=helper(arr,in+1,dp);
        int l=in+1,r=n-1,ans=n;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(arr[mid][0]>arr[in][1])
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        int op2=1+helper(arr,ans,dp);
        return dp[in]=max(op1,op2);
    }

    int findLongestChain(vector<vector<int>>& arr) 
    {
        sort(arr.begin(),arr.end());
        n=arr.size();
        vector<int>dp(n,-1);
        return helper(arr,0,dp);
    }
};
