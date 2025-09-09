class Solution {
public:

    int n;
    int helper(int in,vector<int>&a,int d,vector<vector<int>>&dp)
    {
        if(in>=n)return 1E6;
        if(dp[in][d]!=-1)return dp[in][d];
        if(d==1)
        {
            int maxi=0;
            for(int j=in;j<n;j++)maxi=max(maxi,a[j]);
            return maxi;
        }
        int ans=1E6;
        int maxi=0;
        for(int j=in;j<n;j++)
        {
            maxi=max(maxi,a[j]);
            int res=maxi+helper(j+1,a,d-1,dp);
            ans=min(ans,res);
        }
        return dp[in][d]=ans;
    }

    int minDifficulty(vector<int>& a, int d) 
    {
        n=a.size();
        vector<vector<int>>dp(n,vector<int>(d+1,-1));
        int ans=helper(0,a,d,dp);
        if(ans==1E6)ans=-1;
        return ans;
    }
};
