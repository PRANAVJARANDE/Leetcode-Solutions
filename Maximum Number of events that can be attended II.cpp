class Solution {
public:
    int n;
    int helper(vector<vector<int>>&arr,int k,int in,vector<vector<int>>&dp)
    {
        if(in>=n || k<=0)
            return 0;

        if(dp[in][k]!=-1)
            return dp[in][k];

        int ntake=helper(arr,k,in+1,dp);
        int ans=n,l=in+1,r=n-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(arr[in][1]>=arr[mid][0])
            {
                l=mid+1;
            }
            else
            {
                ans=mid;
                r=mid-1;
            }
        }
        int take=arr[in][2]+helper(arr,k-1,ans,dp);
        return dp[in][k]=max(take,ntake);
    }

    int maxValue(vector<vector<int>>& arr, int k) 
    {
        n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return helper(arr,k,0,dp);
    }
};
