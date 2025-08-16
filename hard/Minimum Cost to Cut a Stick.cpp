class Solution {
public:

    int helper(int i,int j,vector<int>&a,vector<vector<int>>&dp)
    {
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int p=i+1;p<j;p++)
        {
            int res=a[j]-a[i]+helper(i,p,a,dp)+helper(p,j,a,dp);
            ans=min(ans,res);
        }
        if(ans==INT_MAX)ans=0;
        return dp[i][j]=ans;
    }

    int minCost(int l, vector<int>& a) 
    {
        a.push_back(0);
        a.push_back(l);
        sort(a.begin(),a.end());
        int n=a.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=helper(0,n-1,a,dp);
        return ans;
    }
};
