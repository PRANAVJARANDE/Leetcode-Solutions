class Solution {
public:

    int n;
    long long helper(int in,vector<vector<int>>&a,vector<long long>&dp)
    {
        if(in>=n)return 0;
        if(dp[in]!=-1)return dp[in];
        long long op1=a[in][0]+helper(in+a[in][1]+1,a,dp);
        long long op2=helper(in+1,a,dp);
        return dp[in]=max(op1,op2);
    }

    long long mostPoints(vector<vector<int>>& a) {
        n=a.size();
        vector<long long>dp(n,-1);
        long long ans=helper(0,a,dp);
        return ans;
    }
};
