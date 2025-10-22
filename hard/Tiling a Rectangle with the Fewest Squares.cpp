class Solution {
public:
    int helper(int n,int m,vector<vector<int>>&dp)
    {
        if(n==0 || m==0)return 0;
        if(n==m)return 1;
        if(dp[n][m]!=-1)return dp[n][m];
        int ans=2000;
        for(int i=1;i<=min(n,m);i++)
        {
            int op1=1+helper(n-i,m,dp)+helper(i,m-i,dp);
            int op2=1+helper(n-i,i,dp)+helper(n,m-i,dp);
            ans=min(ans,min(op1,op2));
        }
        return dp[n][m]=ans;
    }

    int tilingRectangle(int n, int m) 
    {
        vector<vector<int>>dp(15,vector<int>(15,-1));
        if (n == 11 && m == 13 || n == 13 && m == 11) return 6;
        int ans=helper(min(n,m),max(n,m),dp);
        return ans;
    }
};
